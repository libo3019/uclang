
@begin
include "uccan_module.h"
@end

// - UCCAN indexes of built in classes -
unsigned c_bi_class_can_obj_dict = c_idx_not_exist;
unsigned c_bi_class_can_object = c_idx_not_exist;

// - UCCAN module -
built_in_module_s module =
{/*{{{*/
  2,                     // Class count
  uccan_classes,         // Classes

  0,                     // Error base index
  3,                     // Error count
  uccan_error_strings,   // Error strings

  uccan_initialize,      // Initialize function
  uccan_print_exception, // Print exceptions function
};/*}}}*/

// - UCCAN classes -
built_in_class_s *uccan_classes[] =
{/*{{{*/
  &can_obj_dict_class,
  &can_object_class,
};/*}}}*/

// - UCCAN error strings -
const char *uccan_error_strings[] =
{/*{{{*/
  "error_CAN_OBJECT_DICT_CREATE_ERROR",
  "error_CAN_OBJECT_DICT_OPEN_ERROR",
  "error_CAN_OBJECT_DICT_INDEX_NOT_PRESENT",
};/*}}}*/

// - UCCAN initialize -
bool uccan_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize can_obj_dict class identifier -
  c_bi_class_can_obj_dict = class_base_idx++;

  // - initialize can_object class identifier -
  c_bi_class_can_object = class_base_idx++;

  return true;
}/*}}}*/

// - UCCAN print exception -
bool uccan_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_CAN_OBJECT_DICT_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating CAN object dictionary \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_DICT_OPEN_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while openning CAN object dictionary \"%s\"\n",((string_s *)((location_s *)exception.obj_location)->v_data_ptr)->data);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CAN_OBJECT_DICT_INDEX_NOT_PRESENT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCAN object dictionary does not contain index %" HOST_LL_FORMAT "d:%" HOST_LL_FORMAT "d\n",exception.params[0],exception.params[1]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class CAN_OBJ_DICT -
built_in_class_s can_obj_dict_class =
{/*{{{*/
  "CanObjDict",
  c_modifier_public | c_modifier_final,
  6, can_obj_dict_methods,
  0, can_obj_dict_variables,
  bic_can_obj_dict_consts,
  bic_can_obj_dict_init,
  bic_can_obj_dict_clear,
  NULL,
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

built_in_method_s can_obj_dict_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_operator_binary_equal
  },
  {
    "CanObjDict#1",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_method_CanObjDict_1
  },
  {
    "CanObjDict#4",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_method_CanObjDict_4
  },
  {
    "FindObj#2",
    c_modifier_public | c_modifier_final,
    bic_can_obj_dict_method_FindObj_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_can_obj_dict_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_can_obj_dict_method_print_0
  },
};/*}}}*/

built_in_variable_s can_obj_dict_variables[] =
{/*{{{*/
};/*}}}*/

void bic_can_obj_dict_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_can_obj_dict_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (can_obj_dict_s *)NULL;
}/*}}}*/

void bic_can_obj_dict_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)location_ptr->v_data_ptr;

  if (cod_ptr != NULL)
  {
    cod_ptr->clear(it);
    cfree(cod_ptr);
  }
}/*}}}*/

bool bic_can_obj_dict_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_CanObjDict_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CanObjDict#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;

  ObjDict *dict_ptr = new ObjDict();

  try
  {
    // - open object dictionary -
    dict_ptr->Open(String(name_ptr->data));
  }

  // - ERROR -
  catch (Exception e)
  {
    delete dict_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_DICT_OPEN_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create new can obj dict object -
  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)cmalloc(sizeof(can_obj_dict_s));
  cod_ptr->eds_builder = false;
  cod_ptr->dict_ptr = dict_ptr;

  // - set destination data pointer -
  dst_location->v_data_ptr = (can_obj_dict_s *)cod_ptr;

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_CanObjDict_4(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);
  location_s *src_2_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_2_op_idx]);
  location_s *src_3_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_3_op_idx]);

  long long int size;
  long long int node_id;

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_1_location,size) ||
      src_2_location->v_type != c_bi_class_string ||
      !it.retrieve_integer(src_3_location,node_id))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("CanObjDict#4");
    new_exception->params.push(4);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);
    new_exception->params.push(src_2_location->v_type);
    new_exception->params.push(src_3_location->v_type);

    return false;
  }

  string_s *name_ptr = (string_s *)src_0_location->v_data_ptr;
  string_s *file_ptr = (string_s *)src_2_location->v_data_ptr;

  LodEdsBuilder *dict_ptr = new LodEdsBuilder();

  try
  {
    // - create object dictionary -
    dict_ptr->Create(String(name_ptr->data),size,String(file_ptr->data),node_id);
  }

  // - ERROR -
  catch (Exception e)
  {
    delete dict_ptr;

    exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_DICT_CREATE_ERROR,operands[c_source_pos_idx],src_0_location);
    return false;
  }

  // - create new can obj dict object -
  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)cmalloc(sizeof(can_obj_dict_s));
  cod_ptr->eds_builder = true;
  cod_ptr->dict_ptr = dict_ptr;

  // - set destination data pointer -
  dst_location->v_data_ptr = (can_obj_dict_s *)cod_ptr;

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_FindObj_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);
  location_s *src_1_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_1_op_idx]);

  long long int index;
  long long int sub_index;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,index) ||
      !it.retrieve_integer(src_1_location,sub_index))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("FindObj#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  can_obj_dict_s *cod_ptr = (can_obj_dict_s *)dst_location->v_data_ptr;
  ObjDictBase::Mux mux(index,sub_index);

  // - create new can object -
  can_object_s *co_ptr = (can_object_s *)cmalloc(sizeof(can_object_s));

  // - find object in dictionary -
  U32 result = cod_ptr->dict_ptr->FindObj(mux,co_ptr->handle);

  // - ERROR -
  if (result != SDO_ABORT_OK)
  {
    cfree(co_ptr);

    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CAN_OBJECT_DICT_INDEX_NOT_PRESENT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(mux.idx);
    new_exception->params.push(mux.sidx);

    return false;
  }

  dst_location->v_reference_cnt.atomic_inc();
  co_ptr->dict_loc = dst_location;

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_can_object,co_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CanObjDict"),"CanObjDict")
  );

  return true;
}/*}}}*/

bool bic_can_obj_dict_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("CanObjDict");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class CAN_OBJECT -
built_in_class_s can_object_class =
{/*{{{*/
  "CanObject",
  c_modifier_public | c_modifier_final,
  3, can_object_methods,
  0, can_object_variables,
  bic_can_object_consts,
  bic_can_object_init,
  bic_can_object_clear,
  NULL,
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

built_in_method_s can_object_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_can_object_operator_binary_equal
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_can_object_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_can_object_method_print_0
  },
};/*}}}*/

built_in_variable_s can_object_variables[] =
{/*{{{*/
};/*}}}*/

void bic_can_object_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_can_object_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (can_object_s *)NULL;
}/*}}}*/

void bic_can_object_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  can_object_s *co_ptr = (can_object_s *)location_ptr->v_data_ptr;

  if (co_ptr != NULL)
  {
    co_ptr->clear(it);
    cfree(co_ptr);
  }
}/*}}}*/

bool bic_can_object_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_can_object_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("CanObject"),"CanObject")
  );

  return true;
}/*}}}*/

bool bic_can_object_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("CanObject");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

