
@begin
include "crypto_module.h"
@end

// - CRYPTO indexes of built in classes -
unsigned c_bi_class_crypto = c_idx_not_exist;

// - CRYPTO module -
built_in_module_s module =
{/*{{{*/
  1,                      // Class count
  crypto_classes,         // Classes

  0,                      // Error base index
  2,                      // Error count
  crypto_error_strings,   // Error strings

  crypto_initialize,      // Initialize function
  crypto_print_exception, // Print exceptions function
};/*}}}*/

// - CRYPTO classes -
built_in_class_s *crypto_classes[] =
{/*{{{*/
  &crypto_class,
};/*}}}*/

// - CRYPTO error strings -
const char *crypto_error_strings[] =
{/*{{{*/
  "error_CRYPTO_INVALID_BASE_DATA_SIZE",
  "error_CRYPTO_INVALID_BASE_DATA",
};/*}}}*/

// - CRYPTO initialize -
bool crypto_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize crypto class identifier -
  c_bi_class_crypto = class_base_idx++;

  return true;
}/*}}}*/

// - CRYPTO print exception -
bool crypto_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_CRYPTO_INVALID_BASE_DATA_SIZE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid base%" HOST_LL_FORMAT "d encoded data size\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_CRYPTO_INVALID_BASE_DATA:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid base%" HOST_LL_FORMAT "d encoded data\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class CRYPTO -
built_in_class_s crypto_class =
{/*{{{*/
  "Crypto",
  c_modifier_public | c_modifier_final,
  7, crypto_methods,
  0, crypto_variables,
  bic_crypto_consts,
  bic_crypto_init,
  bic_crypto_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr
};/*}}}*/

built_in_method_s crypto_methods[] =
{/*{{{*/
  {
    "random#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_random_1
  },
  {
    "encode_base16#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_encode_base16_1
  },
  {
    "decode_base16#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_decode_base16_1
  },
  {
    "encode_base64#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_encode_base64_1
  },
  {
    "decode_base64#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_decode_base64_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_crypto_method_print_0
  },
};/*}}}*/

built_in_variable_s crypto_variables[] =
{/*{{{*/
};/*}}}*/

void bic_crypto_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_crypto_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_crypto_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_crypto_method_random_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  long long int size;

  // - ERROR -
  if (!it.retrieve_integer(src_0_location,size))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"random#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->create(size);

  RAND_bytes((unsigned char *)string_ptr->data,size);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,string_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_encode_base16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"encode_base16#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned s_length = source_ptr->size - 1;

  string_s *target_ptr = it.get_new_string_ptr();

  if (s_length != 0)
  {
    target_ptr->create(s_length << 1);

    unsigned char *s_ptr = (unsigned char *)source_ptr->data;
    unsigned char *s_ptr_end = s_ptr + s_length;
    unsigned char *t_ptr = (unsigned char *)target_ptr->data;

    do {
      *t_ptr++ = c_base16_map[*s_ptr >> 4];
      *t_ptr++ = c_base16_map[*s_ptr & 0x0f];
    } while(++s_ptr < s_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_decode_base16_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"decode_base16#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned s_length = source_ptr->size - 1;

  // - ERROR -
  if (s_length & 0x01)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_INVALID_BASE_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(16);

    return false;
  }

  string_s *target_ptr = it.get_new_string_ptr();

  if (s_length != 0)
  {
    target_ptr->create(s_length >> 1);

    unsigned char *s_ptr = (unsigned char *)source_ptr->data;
    unsigned char *s_ptr_end = s_ptr + s_length;
    unsigned char *t_ptr = (unsigned char *)target_ptr->data;

#define BIC_CRYPTO_METHOD_DECODE_BASE16_CHARACTER(OPERATOR) \
{/*{{{*/\
  unsigned char ch = *s_ptr++;\
  \
  if (ch >= '0' && ch <= '9')\
  {\
    *t_ptr OPERATOR ch - '0';\
  }\
  else if (ch >= 'a' && ch <= 'f')\
  {\
    *t_ptr OPERATOR 10 + (ch - 'a');\
  }\
  else if (ch >= 'A' && ch <= 'F')\
  {\
    *t_ptr OPERATOR 10 + (ch - 'A');\
  }\
  \
  /* - ERROR - */\
  else\
  {\
    target_ptr->clear();\
    cfree(target_ptr);\
    \
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_INVALID_BASE_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    new_exception->params.push(16);\
    \
    return false;\
  }\
}/*}}}*/

    do {
      BIC_CRYPTO_METHOD_DECODE_BASE16_CHARACTER(=);
      *t_ptr <<= 4;
      BIC_CRYPTO_METHOD_DECODE_BASE16_CHARACTER(+=);
    } while(++t_ptr,s_ptr < s_ptr_end);
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_encode_base64_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"encode_base64#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned s_length = source_ptr->size - 1;

  string_s *target_ptr = it.get_new_string_ptr();

  if (s_length != 0)
  {
    target_ptr->create(((s_length/3 + 1) << 2) + 1);

    target_ptr->size = EVP_EncodeBlock(
        (unsigned char *)target_ptr->data,
        (unsigned char *)source_ptr->data,
        s_length) + 1;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_decode_base64_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_crypto,"encode_base64#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  unsigned s_length = source_ptr->size - 1;

  // - ERROR -
  if (s_length % 3)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_INVALID_BASE_DATA_SIZE,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(64);

    return false;
  }

  string_s *target_ptr = it.get_new_string_ptr();

  if (s_length != 0)
  {
    target_ptr->create(((s_length >> 2) * 3) + 1);

    int length = EVP_DecodeBlock(
        (unsigned char *)target_ptr->data,
        (unsigned char *)source_ptr->data,
        s_length);

    // - ERROR -
    if (length == -1)
    {
      target_ptr->clear();
      cfree(target_ptr);

      exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_CRYPTO_INVALID_BASE_DATA,operands[c_source_pos_idx],(location_s *)it.blank_location);
      new_exception->params.push(64);

      return false;
    }

    target_ptr->size = length + 1;
  }

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_string,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_crypto_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Crypto"),"Crypto");
  );

  return true;
}/*}}}*/

bool bic_crypto_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Crypto");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

