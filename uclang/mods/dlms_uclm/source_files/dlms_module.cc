
@begin
include "dlms_module.h"
@end

// - DLMS indexes of built in classes -
unsigned c_bi_class_dlms_server = c_idx_not_exist;

// - DLMS module -
built_in_module_s module =
{/*{{{*/
  1,                    // Class count
  dlms_classes,         // Classes

  0,                    // Error base index
  2,                    // Error count
  dlms_error_strings,   // Error strings

  dlms_initialize,      // Initialize function
  dlms_print_exception, // Print exceptions function
};/*}}}*/

// - DLMS classes -
built_in_class_s *dlms_classes[] =
{/*{{{*/
  &dlms_server_class,
};/*}}}*/

// - DLMS error strings -
const char *dlms_error_strings[] =
{/*{{{*/
  "error_DLMS_SERVER_INVALID_PORT_VALUE",
  "error_DLMS_SERVER_CREATE_ERROR",
};/*}}}*/

// - DLMS initialize -
bool dlms_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize dlms_server class identifier -
  c_bi_class_dlms_server = class_base_idx++;

  return true;
}/*}}}*/

// - DLMS print exception -
bool dlms_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_DLMS_SERVER_INVALID_PORT_VALUE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid port %" HOST_LL_FORMAT "d for DLMS server\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_DLMS_SERVER_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError received while creating DLMS server\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class DLMS_SERVER -
built_in_class_s dlms_server_class =
{/*{{{*/
  "DlmsServer",
  c_modifier_public | c_modifier_final,
  4, dlms_server_methods,
  0, dlms_server_variables,
  bic_dlms_server_consts,
  bic_dlms_server_init,
  bic_dlms_server_clear,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL
};/*}}}*/

built_in_method_s dlms_server_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_operator_binary_equal
  },
  {
    "DlmsServer#1",
    c_modifier_public | c_modifier_final,
    bic_dlms_server_method_DlmsServer_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_server_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_dlms_server_method_print_0
  },
};/*}}}*/

built_in_variable_s dlms_server_variables[] =
{/*{{{*/
};/*}}}*/

void bic_dlms_server_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_dlms_server_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_dlms_server_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  CGXDLMSBase *dlmss_ptr = (CGXDLMSBase *)location_ptr->v_data_ptr;

  if (dlmss_ptr != NULL)
  {
    delete dlmss_ptr;
  }
}/*}}}*/

bool bic_dlms_server_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_dlms_server_method_DlmsServer_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int port;

  if (!it.retrieve_integer(src_0_location,port))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("DlmsServer#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - ERROR -
  if (port < 1 || port > 65535)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_INVALID_PORT_VALUE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(port);

    return false;
  }

  // - create dlms server object -
  CGXDLMSBase *dlmss_ptr = new CGXDLMSBase(true,GXDLMS_INTERFACETYPE_GENERAL);

  // - initialize dlms server -
  if (dlmss_ptr->Init(port) != ERROR_CODES_OK)
  {
    delete dlmss_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_DLMS_SERVER_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set destination data pointer -
  dst_location->v_data_ptr = (basic_64b)dlmss_ptr;

  return true;
}/*}}}*/

bool bic_dlms_server_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("DlmsServer"),"DlmsServer");
  );

  return true;
}/*}}}*/

bool bic_dlms_server_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("DlmsServer");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

