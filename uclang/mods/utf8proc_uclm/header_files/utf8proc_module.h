
#ifndef __UTF8PROC_MODULE_H
#define __UTF8PROC_MODULE_H

@begin
include "ucl_utf8proc.h"
@end

// - UTF8PROC indexes of built in classes -
extern unsigned c_bi_class_utf8proc;

// - UTF8PROC module -
extern built_in_module_s module;

// - UTF8PROC classes -
extern built_in_class_s *utf8proc_classes[];

// - UTF8PROC error identifiers -
enum
{
  c_error_UTF8PROC_DECOMPOSE_ERROR = 0,
  c_error_UTF8PROC_UTF8_SEQUENCE_INVALID_CODE_POINT,
};

// - UTF8PROC error strings -
extern const char *utf8proc_error_strings[];

// - UTF8PROC initialize -
bool utf8proc_initialize(script_parser_s &sp);

// - UTF8PROC print exception -
bool utf8proc_print_exception(interpreter_s &it,exception_s &exception);

// - class UTF8PROC -
extern built_in_variable_s utf8proc_variables[];
extern built_in_method_s utf8proc_methods[];
extern built_in_class_s utf8proc_class;

void bic_utf8proc_consts(location_array_s &const_locations);
void bic_utf8proc_init(interpreter_thread_s &it,location_s *location_ptr);
void bic_utf8proc_clear(interpreter_thread_s &it,location_s *location_ptr);

bool bic_utf8proc_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_decompose_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_to_lower_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
//bool bic_utf8proc_method_to_upper_1(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_version_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);
bool bic_utf8proc_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands);

#endif

