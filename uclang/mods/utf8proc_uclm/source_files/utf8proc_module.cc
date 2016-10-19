
@begin
include "utf8proc_module.h"
@end

// - UTF8PROC indexes of built in classes -
unsigned c_bi_class_utf8proc = c_idx_not_exist;
unsigned c_bi_class_unicode_str = c_idx_not_exist;

// - UTF8PROC module -
built_in_module_s module =
{/*{{{*/
  2,                        // Class count
  utf8proc_classes,         // Classes

  0,                        // Error base index
  3,                        // Error count
  utf8proc_error_strings,   // Error strings

  utf8proc_initialize,      // Initialize function
  utf8proc_print_exception, // Print exceptions function
};/*}}}*/

// - UTF8PROC classes -
built_in_class_s *utf8proc_classes[] =
{/*{{{*/
  &utf8proc_class,
  &unicode_str_class,
};/*}}}*/

// - UTF8PROC error strings -
const char *utf8proc_error_strings[] =
{/*{{{*/
  "error_UTF8PROC_UTF8_SEQUENCE_INVALID_CODE_POINT",
  "error_UNICODE_STRING_UTF8_DECOMPOSE_ERROR",
  "error_UNICODE_STRING_UTF8_CREATE_ERROR",
};/*}}}*/

// - UTF8PROC initialize -
bool utf8proc_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize utf8proc class identifier -
  c_bi_class_utf8proc = class_base_idx++;

  // - initialize unicode_str class identifier -
  c_bi_class_unicode_str = class_base_idx++;

  return true;
}/*}}}*/

// - UTF8PROC print exception -
bool utf8proc_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  ui_array_s class_stack;
  class_stack.init();

  switch (exception.type - module.error_base)
  {
  case c_error_UTF8PROC_UTF8_SEQUENCE_INVALID_CODE_POINT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nCannot read valid code point from UTF-8 sequence\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UNICODE_STRING_UTF8_DECOMPOSE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while decomposing UTF-8 sequence to code points\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_UNICODE_STRING_UTF8_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating UTF-8 sequence from code points\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    class_stack.clear();
    return false;
  }

  class_stack.clear();

  return true;
}/*}}}*/

// - class UTF8PROC -
built_in_class_s utf8proc_class =
{/*{{{*/
  "Utf8Proc",
  c_modifier_public | c_modifier_final,
  6, utf8proc_methods,
  0, utf8proc_variables,
  bic_utf8proc_consts,
  bic_utf8proc_init,
  bic_utf8proc_clear,
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

built_in_method_s utf8proc_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_utf8proc_operator_binary_equal
  },
  {
    "to_lower#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_to_lower_1
  },
  {
    "to_upper#1",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_to_upper_1
  },
  {
    "version#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_version_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_utf8proc_method_print_0
  },
};/*}}}*/

built_in_variable_s utf8proc_variables[] =
{/*{{{*/
};/*}}}*/

#define BIC_UTF8PROC_TRANSFORM_STRING(CODE_POINT_CODE) \
/*{{{*/\
\
  /* - create target buffer - */\
  bc_array_s buffer;\
  buffer.init_size(source_ptr->size);\
\
  if (source_ptr->size > 1)\
  {\
    const utf8proc_uint8_t *s_ptr = (const utf8proc_uint8_t *)source_ptr->data;\
    const utf8proc_uint8_t *s_ptr_end = s_ptr + source_ptr->size - 1;\
\
    utf8proc_int32_t code_point;\
    do {\
      \
      /* - retrieve next code point - */\
      s_ptr += utf8proc_iterate(s_ptr,s_ptr_end - s_ptr,&code_point);\
\
      /* - ERROR - */\
      if (code_point < 0)\
      {\
        buffer.clear();\
\
        exception_s::throw_exception(it,module.error_base + c_error_UTF8PROC_UTF8_SEQUENCE_INVALID_CODE_POINT,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
\
      CODE_POINT_CODE;\
\
      /* - encode code point to target buffer - */\
      buffer.reserve(4);\
      buffer.used += utf8proc_encode_char(code_point,\
          (utf8proc_uint8_t *)(buffer.data + buffer.used));\
\
    } while(s_ptr < s_ptr_end);\
  }\
\
  buffer.push('\0');\
\
  /* - create target string - */\
  string_s *target_ptr = it.get_new_string_ptr();\
  target_ptr->data = buffer.data;\
  target_ptr->size = buffer.used;\
/*}}}*/

void bic_utf8proc_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_utf8proc_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

void bic_utf8proc_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  cassert(0);
}/*}}}*/

bool bic_utf8proc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_utf8proc_method_to_lower_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_utf8proc,"to_lower#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  BIC_UTF8PROC_TRANSFORM_STRING(

    // - code point to lower -
    code_point = utf8proc_tolower(code_point);
  );

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_utf8proc_method_to_upper_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI_CLASS_IDX(it,c_bi_class_utf8proc,"to_lower#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;

  BIC_UTF8PROC_TRANSFORM_STRING(

    // - code point to upper -
    code_point = utf8proc_toupper(code_point);
  );

  BIC_SET_RESULT_STRING(target_ptr);

  return true;
}/*}}}*/

bool bic_utf8proc_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  const char *version = utf8proc_version();

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(strlen(version),version);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_utf8proc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("Utf8Proc"),"Utf8Proc");
  );

  return true;
}/*}}}*/

bool bic_utf8proc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];

  printf("Utf8Proc");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class UNICODE_STR -
built_in_class_s unicode_str_class =
{/*{{{*/
  "UnicodeStr",
  c_modifier_public | c_modifier_final,
  6, unicode_str_methods,
  0, unicode_str_variables,
  bic_unicode_str_consts,
  bic_unicode_str_init,
  bic_unicode_str_clear,
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

built_in_method_s unicode_str_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_str_operator_binary_equal
  },
  {
    "UnicodeStr#1",
    c_modifier_public | c_modifier_final,
    bic_unicode_str_method_UnicodeStr_1
  },
  {
    "to_lower#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_str_method_to_lower_0
  },
  {
    "to_upper#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_str_method_to_upper_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_str_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final,
    bic_unicode_str_method_print_0
  },
};/*}}}*/

built_in_variable_s unicode_str_variables[] =
{/*{{{*/
};/*}}}*/

void bic_unicode_str_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_unicode_str_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (basic_64b)NULL;
}/*}}}*/

void bic_unicode_str_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  ui_array_s *ustring_ptr = (ui_array_s *)location_ptr->v_data_ptr;

  // - if websocket context exists -
  if (ustring_ptr != NULL)
  {
    ustring_ptr->clear();
    cfree(ustring_ptr);
  }
}/*}}}*/

bool bic_unicode_str_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  pointer &dst_location = it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_unicode_str_method_UnicodeStr_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  // - ERROR -
  if (src_0_location->v_type != c_bi_class_string)
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("UnicodeStr#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  string_s *source_ptr = (string_s *)src_0_location->v_data_ptr;
  utf8proc_ssize_t source_length = source_ptr->size - 1;

  // - create unicode string -
  ui_array_s *ustring_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));
  ustring_ptr->init_size(source_length);

  utf8proc_ssize_t cp_count = utf8proc_decompose(
      (const utf8proc_uint8_t *)source_ptr->data,source_length,
      (utf8proc_int32_t *)ustring_ptr->data,source_length,
      (utf8proc_option_t)0);

  // - ERROR -
  if (cp_count < 0 || cp_count > source_length)
  {
    ustring_ptr->clear();
    cfree(ustring_ptr);

    exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_UTF8_DECOMPOSE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  // - set count of code points -
  ustring_ptr->used = cp_count;

  dst_location->v_data_ptr = (basic_64b)ustring_ptr;

  return true;
}/*}}}*/

#define BIC_UNICODE_STR_TRANSFORM_STRING(CODE_POINT_CODE) \
/*{{{*/\
\
  /* - create target unicode string - */\
  ui_array_s *target_ptr = (ui_array_s *)cmalloc(sizeof(ui_array_s));\
  target_ptr->init_size(source_ptr->used);\
\
  if (source_ptr->used != 0)\
  {\
    utf8proc_int32_t *s_ptr = (utf8proc_int32_t *)source_ptr->data;\
    utf8proc_int32_t *s_ptr_end = s_ptr + source_ptr->used;\
    utf8proc_int32_t *t_ptr = (utf8proc_int32_t *)target_ptr->data;\
    do {\
      CODE_POINT_CODE;\
    } while(++t_ptr,++s_ptr < s_ptr_end);\
  }\
\
  target_ptr->used = source_ptr->used;\
/*}}}*/

bool bic_unicode_str_method_to_lower_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ui_array_s *source_ptr = (ui_array_s *)dst_location->v_data_ptr;

  BIC_UNICODE_STR_TRANSFORM_STRING(

    // - code point to lower -
    *t_ptr = utf8proc_tolower(*s_ptr);
  )

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_str,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_str_method_to_upper_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ui_array_s *source_ptr = (ui_array_s *)dst_location->v_data_ptr;

  BIC_UNICODE_STR_TRANSFORM_STRING(

    // - code point to upper -
    *t_ptr = utf8proc_toupper(*s_ptr);
  )

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_unicode_str,target_ptr);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_unicode_str_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ui_array_s *ustring_ptr = (ui_array_s *)dst_location->v_data_ptr;

  bc_array_s buffer;
  buffer.init();

  // - ERROR -
  if (!utf8proc_s::unicode_to_utf8(*ustring_ptr,buffer))
  {
    buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_UTF8_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  buffer.push('\0');

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->data = buffer.data;
  string_ptr->size = buffer.used;

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_unicode_str_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  pointer &res_location = it.data_stack[stack_base + operands[c_res_op_idx]];
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  ui_array_s *ustring_ptr = (ui_array_s *)dst_location->v_data_ptr;

  bc_array_s buffer;
  buffer.init();

  // - ERROR -
  if (!utf8proc_s::unicode_to_utf8(*ustring_ptr,buffer))
  {
    buffer.clear();

    exception_s::throw_exception(it,module.error_base + c_error_UNICODE_STRING_UTF8_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  fwrite(buffer.data,buffer.used,1,stdout);

  buffer.clear();

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

