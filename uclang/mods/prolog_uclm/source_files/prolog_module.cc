
@begin
include "prolog_module.h"
@end

// - PROLOG indexes of built in classes -
unsigned c_bi_class_prolog_module = c_idx_not_exist;
unsigned c_bi_class_prolog_atom = c_idx_not_exist;
unsigned c_bi_class_prolog_frame = c_idx_not_exist;
unsigned c_bi_class_prolog_functor = c_idx_not_exist;
unsigned c_bi_class_prolog_term = c_idx_not_exist;
unsigned c_bi_class_prolog_pred = c_idx_not_exist;
unsigned c_bi_class_prolog_query = c_idx_not_exist;

// - PROLOG indexes of remote classes -
unsigned c_rm_class_dict = c_idx_not_exist;

// - PROLOG module -
EXPORT built_in_module_s module =
{/*{{{*/
  7,                      // Class count
  prolog_classes,         // Classes

  0,                      // Error base index
  8,                      // Error count
  prolog_error_strings,   // Error strings

  prolog_initialize,      // Initialize function
  prolog_print_exception, // Print exceptions function
};/*}}}*/

// - PROLOG classes -
built_in_class_s *prolog_classes[] =
{/*{{{*/
  &prolog_module_class,
  &prolog_atom_class,
  &prolog_frame_class,
  &prolog_functor_class,
  &prolog_term_class,
  &prolog_pred_class,
  &prolog_query_class,
};/*}}}*/

// - PROLOG error strings -
const char *prolog_error_strings[] =
{/*{{{*/
  "error_PROLOG_PRED_INVALID_TERM_COUNT",
  "error_PROLOG_TERM_WRONG_TERM_REFERENCE",
  "error_PROLOG_TERM_CREATE_ERROR",
  "error_PROLOG_TERM_COMPOUND_CREATE_ERROR",
  "error_PROLOG_TERM_VALUE_ERROR",
  "error_PROLOG_QUERY_ALREADY_ACTIVE",
  "error_PROLOG_QUERY_CREATE_ERROR",
  "error_PROLOG_QUERY_EXCEPTION",
};/*}}}*/

// - PROLOG initialize -
bool prolog_initialize(script_parser_s &sp)
{/*{{{*/
  unsigned class_base_idx = sp.class_records.used - module.class_cnt;

  // - initialize prolog_module class identifier -
  c_bi_class_prolog_module = class_base_idx++;

  // - initialize prolog_atom class identifier -
  c_bi_class_prolog_atom = class_base_idx++;

  // - initialize prolog_frame class identifier -
  c_bi_class_prolog_frame = class_base_idx++;

  // - initialize prolog_functor class identifier -
  c_bi_class_prolog_functor = class_base_idx++;

  // - initialize prolog_term class identifier -
  c_bi_class_prolog_term = class_base_idx++;

  // - initialize prolog_pred class identifier -
  c_bi_class_prolog_pred = class_base_idx++;

  // - initialize prolog_query class identifier -
  c_bi_class_prolog_query = class_base_idx++;

  return true;
}/*}}}*/

// - PROLOG print exception -
bool prolog_print_exception(interpreter_s &it,exception_s &exception)
{/*{{{*/
  unsigned source_pos = GET_SRC_POS(exception.position);
  source_s &source = it.sources[GET_SRC_IDX(exception.position)];

  switch (exception.type - module.error_base)
  {
  case c_error_PROLOG_PRED_INVALID_TERM_COUNT:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nInvalid count of terms for predicate, expected %" HOST_LL_FORMAT "d\n",exception.params[0]);
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROLOG_TERM_WRONG_TERM_REFERENCE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nWrong reference to Prolog term\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROLOG_TERM_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating Prolog term\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROLOG_TERM_COMPOUND_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating compound term\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROLOG_TERM_VALUE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while retrieving value of Prolog term\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROLOG_QUERY_ALREADY_ACTIVE:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nSome query is active, only one active query is allowed\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROLOG_QUERY_CREATE_ERROR:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nError while creating Prolog query\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  case c_error_PROLOG_QUERY_EXCEPTION:
    fprintf(stderr," ---------------------------------------- \n");
    fprintf(stderr,"Exception: ERROR: in file: \"%s\" on line: %u\n",source.file_name.data,source.source_string.get_character_line(source_pos));
    print_error_line(source.source_string,source_pos);
    fprintf(stderr,"\nException occurred while executing Prolog query\n");
    fprintf(stderr," ---------------------------------------- \n");
    break;
  default:
    return false;
  }

  return true;
}/*}}}*/

// - class PROLOG_MODULE -
built_in_class_s prolog_module_class =
{/*{{{*/
  "PrologModule",
  c_modifier_public | c_modifier_final,
  8, prolog_module_methods,
  0, prolog_module_variables,
  bic_prolog_module_consts,
  bic_prolog_module_init,
  bic_prolog_module_clear,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  nullptr,
  bic_prolog_module_invoke,
  nullptr
};/*}}}*/

built_in_method_s prolog_module_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_module_operator_binary_equal
  },
  {
    "PrologModule#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_module_method_PrologModule_0
  },
  {
    "PrologModule#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_module_method_PrologModule_1
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_module_method_name_0
  },
  {
    "pred#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_module_method_pred_1
  },
  {
    "pred#2",
    c_modifier_public | c_modifier_final,
    bic_prolog_module_method_pred_2
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_module_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_module_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_module_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

#define BIC_PROLOG_MODULE_OPEN_QUERY(MODULE,PRED,TERMS,ERR_CODE) \
/*{{{*/\
\
  /* - ERROR - */\
  if (prolog_c::qid != 0)\
  {\
    ERR_CODE;\
\
    exception_s::throw_exception(it,module.error_base + c_error_PROLOG_QUERY_ALREADY_ACTIVE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
\
  /* - create query - */\
  prolog_c::qid = PL_open_query(MODULE,PL_Q_NORMAL | PL_Q_CATCH_EXCEPTION,PRED,TERMS);\
\
  /* - ERROR - */\
  if (prolog_c::qid == 0)\
  {\
    ERR_CODE;\
\
    exception_s::throw_exception(it,module.error_base + c_error_PROLOG_QUERY_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);\
    return false;\
  }\
/*}}}*/

#define BIC_PROLOG_MODULE_CLOSE_QUERY() \
/*{{{*/\
  PL_close_query(prolog_c::qid);\
  prolog_c::qid = 0;\
/*}}}*/

#define BIC_PROLOG_RETRIEVE_TERMS_FROM_ARRAY(ERR_CODE) \
{/*{{{*/\
  if (arity > 0)\
  {\
    terms = PL_new_term_refs(arity);\
\
    size_t idx = 0;\
    do {\
      location_s *item_location = it.get_location_value(array_ptr->data[idx]);\
\
      /* - ERROR - */\
      if (!prolog_c::create_prolog_term(it,terms + idx,item_location))\
      {\
        ERR_CODE;\
\
        exception_s::throw_exception(it,module.error_base + c_error_PROLOG_TERM_WRONG_TERM_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);\
        return false;\
      }\
    } while(++idx < arity);\
  }\
}/*}}}*/

void bic_prolog_module_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_module_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (module_t)0;
}/*}}}*/

void bic_prolog_module_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_prolog_module_invoke(interpreter_thread_s &it,uli *code,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - method name reference -
  string_s &name_ref = ((interpreter_s *)it.interpreter_ptr)->method_symbol_names[code[icl_name_idx]];

  // - parameter count and method name length -
  unsigned param_cnt = (unsigned)code[icl_parm_cnt] - 1;
  char *name_data = name_ref.data;
  unsigned name_length = strchr(name_data,'#') - name_data;

  // - query or compound term flag -
  bool do_query = true;
  term_t term;

  // - check request for compound term -
  if (*name_data == '_')
  {
    // - remove character '_' from name -
    ++name_data;
    --name_length;
    do_query = false;

    // - alocate compound term reference -
    term = PL_new_term_ref();
  }

  // - create prolog functor from method name and parameter count -
  atom_t atom = PL_new_atom_nchars(name_length,name_data);
  functor_t ftor = PL_new_functor(atom,param_cnt);

  // - prepare parameters -
  fid_t fid = PL_open_foreign_frame();
  term_t terms = 0;

  if (param_cnt > 0)
  {
    terms = PL_new_term_refs(param_cnt);

    unsigned param_idx = 0;
    do {
      location_s *param_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx + param_idx]);

      // - ERROR -
      if (!prolog_c::create_prolog_term(it,terms + param_idx,param_location))
      {
        PL_close_foreign_frame(fid);

        exception_s::throw_exception(it,module.error_base + c_error_PROLOG_TERM_WRONG_TERM_REFERENCE,operands[c_source_pos_idx],(location_s *)it.blank_location);
        return false;
      }
    } while(++param_idx < param_cnt);
  }

  // - if query is requested -
  if (do_query)
  {
    // - create prolog predicate from prolog functor -
    module_t plmod = (module_t)dst_location->v_data_ptr;
    predicate_t pred = PL_pred(ftor,plmod);

    BIC_PROLOG_MODULE_OPEN_QUERY(plmod,pred,terms,
      PL_close_foreign_frame(fid);
    );

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_query,(fid_t)fid);
    BIC_SET_RESULT(new_location);
  }

  // - if compound term is requested -
  else
  {
    // - ERROR -
    if (!PL_cons_functor_v(term,ftor,terms))
    {
      PL_close_foreign_frame(fid);

      exception_s::throw_exception(it,module.error_base + c_error_PROLOG_TERM_COMPOUND_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    PL_close_foreign_frame(fid);

    BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_term,term);
    BIC_SET_RESULT(new_location);
  }

  return true;
}/*}}}*/

bool bic_prolog_module_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_module_method_PrologModule_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - retrieve active context module -
  dst_location->v_data_ptr = (module_t)PL_context();

  return true;
}/*}}}*/

bool bic_prolog_module_method_PrologModule_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:ignore
>
method PrologModule
; @end

  atom_t atom;

  if (!prolog_c::retrieve_atom(src_0_location,atom))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PrologModule#1");
    new_exception->params.push(1);
    new_exception->params.push(src_0_location->v_type);

    return false;
  }

  // - create prolog module -
  module_t plmod = PL_new_module(atom);

  dst_location->v_data_ptr = (module_t)plmod;

  return true;
}/*}}}*/

bool bic_prolog_module_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  atom_t atom = PL_module_name((module_t)dst_location->v_data_ptr);
  PL_register_atom(atom);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_atom,atom);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_prolog_module_method_pred_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
functor:c_bi_class_prolog_functor
>
method pred
; @end

  module_t plmod = (module_t)dst_location->v_data_ptr;
  functor_t ftor = (functor_t)src_0_location->v_data_ptr;

  // - create prolog predicate from functor -
  predicate_t pred = PL_pred(ftor,plmod);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_pred,pred);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_prolog_module_method_pred_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
arity:retrieve_integer
>
method pred
; @end

  module_t plmod = (module_t)dst_location->v_data_ptr;
  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create prolog predicate from name and arity -
  atom_t atom = PL_new_atom_nchars(string_ptr->size - 1,string_ptr->data);
  functor_t ftor = PL_new_functor(atom,arity);
  predicate_t pred = PL_pred(ftor,plmod);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_pred,pred);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_prolog_module_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologModule"),"PrologModule");
  );

  return true;
}/*}}}*/

bool bic_prolog_module_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PrologModule");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROLOG_FRAME -
built_in_class_s prolog_frame_class =
{/*{{{*/
  "PrologFrame",
  c_modifier_public | c_modifier_final,
  4, prolog_frame_methods,
  0, prolog_frame_variables,
  bic_prolog_frame_consts,
  bic_prolog_frame_init,
  bic_prolog_frame_clear,
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

built_in_method_s prolog_frame_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_frame_operator_binary_equal
  },
  {
    "PrologFrame#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_frame_method_PrologFrame_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_frame_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_frame_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_frame_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_prolog_frame_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_frame_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fid_t)0;
}/*}}}*/

void bic_prolog_frame_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fid_t fid = (fid_t)location_ptr->v_data_ptr;
  PL_close_foreign_frame(fid);
}/*}}}*/

bool bic_prolog_frame_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_frame_method_PrologFrame_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  // - open new foreign frame -
  dst_location->v_data_ptr = (fid_t)PL_open_foreign_frame();

  return true;
}/*}}}*/

bool bic_prolog_frame_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologFrame"),"PrologFrame");
  );

  return true;
}/*}}}*/

bool bic_prolog_frame_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PrologFrame");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROLOG_ATOM -
built_in_class_s prolog_atom_class =
{/*{{{*/
  "PrologAtom",
  c_modifier_public | c_modifier_final,
  5, prolog_atom_methods,
  0, prolog_atom_variables,
  bic_prolog_atom_consts,
  bic_prolog_atom_init,
  bic_prolog_atom_clear,
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

built_in_method_s prolog_atom_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_atom_operator_binary_equal
  },
  {
    "PrologAtom#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_atom_method_PrologAtom_1
  },
  {
    "text#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_atom_method_text_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_atom_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_atom_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_atom_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_prolog_atom_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_atom_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (atom_t)0;
}/*}}}*/

void bic_prolog_atom_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  atom_t atom = (atom_t)location_ptr->v_data_ptr;
  PL_unregister_atom(atom);
}/*}}}*/

bool bic_prolog_atom_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_atom_method_PrologAtom_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:c_bi_class_string
>
method PrologAtom
; @end

  string_s *string_ptr = (string_s *)src_0_location->v_data_ptr;

  // - create and register prolog atom -
  atom_t atom = PL_new_atom_nchars(string_ptr->size - 1,string_ptr->data);
  PL_register_atom(atom);

  dst_location->v_data_ptr = (atom_t)atom;

  return true;
}/*}}}*/

bool bic_prolog_atom_method_text_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  atom_t atom = (atom_t)dst_location->v_data_ptr;

  size_t length;
  const char *data = PL_atom_nchars(atom,&length);

  string_s *string_ptr = it.get_new_string_ptr();
  string_ptr->set(length,data);

  BIC_SET_RESULT_STRING(string_ptr);

  return true;
}/*}}}*/

bool bic_prolog_atom_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologAtom"),"PrologAtom");
  );

  return true;
}/*}}}*/

bool bic_prolog_atom_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PrologAtom");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROLOG_FUNCTOR -
built_in_class_s prolog_functor_class =
{/*{{{*/
  "PrologFunctor",
  c_modifier_public | c_modifier_final,
  7, prolog_functor_methods,
  0, prolog_functor_variables,
  bic_prolog_functor_consts,
  bic_prolog_functor_init,
  bic_prolog_functor_clear,
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

built_in_method_s prolog_functor_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_operator_binary_equal
  },
  {
    "PrologFunctor#2",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_method_PrologFunctor_2
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_method_name_0
  },
  {
    "arity#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_method_arity_0
  },
  {
    "term#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_functor_method_term_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_functor_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_functor_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_functor_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_prolog_functor_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_functor_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (functor_t)0;
}/*}}}*/

void bic_prolog_functor_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_prolog_functor_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_functor_method_PrologFunctor_2(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
name:ignore
arity:ignore
>
method PrologFunctor
; @end

  atom_t atom;
  long long int arity;

  if (!prolog_c::retrieve_atom(src_0_location,atom) ||
      !it.retrieve_integer(src_1_location,arity))
  {
    exception_s *new_exception = exception_s::throw_exception(it,c_error_METHOD_NOT_DEFINED_WITH_PARAMETERS,operands[c_source_pos_idx],(location_s *)it.blank_location);
    BIC_EXCEPTION_PUSH_METHOD_RI("PrologFunctor#2");
    new_exception->params.push(2);
    new_exception->params.push(src_0_location->v_type);
    new_exception->params.push(src_1_location->v_type);

    return false;
  }

  // - create prolog functor -
  functor_t ftor = PL_new_functor(atom,arity);

  dst_location->v_data_ptr = (functor_t)ftor;

  return true;
}/*}}}*/

bool bic_prolog_functor_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  atom_t atom = PL_functor_name((functor_t)dst_location->v_data_ptr);
  PL_register_atom(atom);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_atom,atom);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_prolog_functor_method_arity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  long long int arity = PL_functor_arity((functor_t)dst_location->v_data_ptr);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,arity);

  return true;
}/*}}}*/

bool bic_prolog_functor_method_term_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
values:c_bi_class_array
>
method term
; @end

  functor_t ftor = (functor_t)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  // - retrieve functor arity -
  size_t arity = PL_functor_arity(ftor);

  term_t term = PL_new_term_ref();

  // - retrieve functor terms -
  fid_t fid = PL_open_foreign_frame();
  term_t terms = 0;

  BIC_PROLOG_RETRIEVE_TERMS_FROM_ARRAY(
    PL_close_foreign_frame(fid);
  );

  // - ERROR -
  if (!PL_cons_functor_v(term,ftor,terms))
  {
    PL_close_foreign_frame(fid);

    exception_s::throw_exception(it,module.error_base + c_error_PROLOG_TERM_COMPOUND_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  PL_close_foreign_frame(fid);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_term,term);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_prolog_functor_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologFunctor"),"PrologFunctor");
  );

  return true;
}/*}}}*/

bool bic_prolog_functor_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PrologFunctor");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROLOG_TERM -
built_in_class_s prolog_term_class =
{/*{{{*/
  "PrologTerm",
  c_modifier_public | c_modifier_final,
  6, prolog_term_methods,
  0, prolog_term_variables,
  bic_prolog_term_consts,
  bic_prolog_term_init,
  bic_prolog_term_clear,
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

built_in_method_s prolog_term_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_term_operator_binary_equal
  },
  {
    "PrologTerm#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_term_method_PrologTerm_0
  },
  {
    "PrologTerm#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_term_method_PrologTerm_1
  },
  {
    "value#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_term_method_value_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_term_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_term_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_term_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_prolog_term_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_term_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (term_t)0;
}/*}}}*/

void bic_prolog_term_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_prolog_term_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_term_method_PrologTerm_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  dst_location->v_data_ptr = PL_new_term_ref();

  return true;
}/*}}}*/

bool bic_prolog_term_method_PrologTerm_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  term_t term = PL_new_term_ref();

  if (!prolog_c::create_prolog_term(it,term,src_0_location))
  {
    exception_s::throw_exception(it,module.error_base + c_error_PROLOG_TERM_CREATE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  dst_location->v_data_ptr = term;

  return true;
}/*}}}*/

bool bic_prolog_term_method_value_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  term_t term = (term_t)dst_location->v_data_ptr;

  location_s *location_ptr =
    prolog_c::prolog_term_value(it,term,operands[c_source_pos_idx]);

  // - ERROR -
  if (location_ptr == nullptr)
  {
    // - if exception was already thrown -
    if (((location_s *)it.exception_location)->v_type != c_bi_class_blank)
    {
      return false;
    }

    exception_s::throw_exception(it,module.error_base + c_error_PROLOG_TERM_VALUE_ERROR,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_SET_RESULT(location_ptr);

  return true;
}/*}}}*/

bool bic_prolog_term_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologTerm"),"PrologTerm");
  );

  return true;
}/*}}}*/

bool bic_prolog_term_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PrologTerm");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROLOG_PRED -
built_in_class_s prolog_pred_class =
{/*{{{*/
  "PrologPred",
  c_modifier_public | c_modifier_final,
  7, prolog_pred_methods,
  0, prolog_pred_variables,
  bic_prolog_pred_consts,
  bic_prolog_pred_init,
  bic_prolog_pred_clear,
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

built_in_method_s prolog_pred_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_pred_operator_binary_equal
  },
  {
    "name#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_pred_method_name_0
  },
  {
    "arity#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_pred_method_arity_0
  },
  {
    "call#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_pred_method_call_1
  },
  {
    "query#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_pred_method_query_1
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_pred_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_pred_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_pred_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_prolog_pred_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_pred_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (predicate_t)0;
}/*}}}*/

void bic_prolog_pred_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
}/*}}}*/

bool bic_prolog_pred_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_pred_method_name_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  predicate_t pred = (predicate_t)dst_location->v_data_ptr;

  atom_t atom;
  PL_predicate_info(pred,&atom,nullptr,nullptr);
  PL_register_atom(atom);

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_atom,atom);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_prolog_pred_method_arity_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *dst_location = (location_s *)it.get_stack_value(stack_base + operands[c_dst_op_idx]);

  predicate_t pred = (predicate_t)dst_location->v_data_ptr;

  size_t arity;
  PL_predicate_info(pred,nullptr,&arity,nullptr);
  long long int result = arity;

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_prolog_pred_method_call_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
values:c_bi_class_array
>
method call
; @end

  predicate_t pred = (predicate_t)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  size_t arity;
  module_t plmod;
  PL_predicate_info(pred,nullptr,&arity,&plmod);

  // - ERROR -
  if (array_ptr->used != arity)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROLOG_PRED_INVALID_TERM_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(arity);

    return false;
  }

  // - retrieve predicate terms -
  fid_t fid = PL_open_foreign_frame();
  term_t terms = 0;

  BIC_PROLOG_RETRIEVE_TERMS_FROM_ARRAY(
    PL_close_foreign_frame(fid);
  );

  BIC_PROLOG_MODULE_OPEN_QUERY(plmod,pred,terms,
    PL_close_foreign_frame(fid);
  );

  // - retrieve first solution -
  long long int result = PL_next_solution(prolog_c::qid);

  // - ERROR -
  if (PL_exception(prolog_c::qid))
  {
    BIC_PROLOG_MODULE_CLOSE_QUERY();
    PL_close_foreign_frame(fid);

    exception_s::throw_exception(it,module.error_base + c_error_PROLOG_QUERY_EXCEPTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
    return false;
  }

  BIC_PROLOG_MODULE_CLOSE_QUERY();
  PL_close_foreign_frame(fid);

  BIC_SIMPLE_SET_RES(c_bi_class_integer,result);

  return true;
}/*}}}*/

bool bic_prolog_pred_method_query_1(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
@begin ucl_params
<
values:c_bi_class_array
>
method query
; @end

  predicate_t pred = (predicate_t)dst_location->v_data_ptr;
  pointer_array_s *array_ptr = (pointer_array_s *)src_0_location->v_data_ptr;

  size_t arity;
  module_t plmod;
  PL_predicate_info(pred,nullptr,&arity,&plmod);

  // - ERROR -
  if (array_ptr->used != arity)
  {
    exception_s *new_exception = exception_s::throw_exception(it,module.error_base + c_error_PROLOG_PRED_INVALID_TERM_COUNT,operands[c_source_pos_idx],(location_s *)it.blank_location);
    new_exception->params.push(arity);

    return false;
  }

  // - retrieve predicate terms -
  fid_t fid = PL_open_foreign_frame();
  term_t terms = 0;

  BIC_PROLOG_RETRIEVE_TERMS_FROM_ARRAY(
    PL_close_foreign_frame(fid);
  );

  BIC_PROLOG_MODULE_OPEN_QUERY(plmod,pred,terms,
    PL_close_foreign_frame(fid);
  );

  BIC_CREATE_NEW_LOCATION(new_location,c_bi_class_prolog_query,(fid_t)fid);
  BIC_SET_RESULT(new_location);

  return true;
}/*}}}*/

bool bic_prolog_pred_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologPred"),"PrologPred");
  );

  return true;
}/*}}}*/

bool bic_prolog_pred_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PrologPred");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

// - class PROLOG_QUERY -
built_in_class_s prolog_query_class =
{/*{{{*/
  "PrologQuery",
  c_modifier_public | c_modifier_final,
  4, prolog_query_methods,
  0, prolog_query_variables,
  bic_prolog_query_consts,
  bic_prolog_query_init,
  bic_prolog_query_clear,
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

built_in_method_s prolog_query_methods[] =
{/*{{{*/
  {
    "operator_binary_equal#1",
    c_modifier_public | c_modifier_final,
    bic_prolog_query_operator_binary_equal
  },
  {
    "next_item#0",
    c_modifier_public | c_modifier_final,
    bic_prolog_query_method_next_item_0
  },
  {
    "to_string#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_query_method_to_string_0
  },
  {
    "print#0",
    c_modifier_public | c_modifier_final | c_modifier_static,
    bic_prolog_query_method_print_0
  },
};/*}}}*/

built_in_variable_s prolog_query_variables[] =
{/*{{{*/
  BIC_CLASS_EMPTY_VARIABLES
};/*}}}*/

void bic_prolog_query_consts(location_array_s &const_locations)
{/*{{{*/
}/*}}}*/

void bic_prolog_query_init(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  location_ptr->v_data_ptr = (fid_t)0;
}/*}}}*/

void bic_prolog_query_clear(interpreter_thread_s &it,location_s *location_ptr)
{/*{{{*/
  fid_t fid = (fid_t)location_ptr->v_data_ptr;

  BIC_PROLOG_MODULE_CLOSE_QUERY();
  PL_close_foreign_frame(fid);
}/*}}}*/

bool bic_prolog_query_operator_binary_equal(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  location_s *src_0_location = (location_s *)it.get_stack_value(stack_base + operands[c_src_0_op_idx]);

  src_0_location->v_reference_cnt.atomic_add(2);

  BIC_SET_DESTINATION(src_0_location);
  BIC_SET_RESULT(src_0_location);

  return true;
}/*}}}*/

bool bic_prolog_query_method_next_item_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  if (!PL_next_solution(prolog_c::qid))
  {
    // - ERROR -
    if (PL_exception(prolog_c::qid))
    {
      exception_s::throw_exception(it,module.error_base + c_error_PROLOG_QUERY_EXCEPTION,operands[c_source_pos_idx],(location_s *)it.blank_location);
      return false;
    }

    BIC_SET_RESULT_BLANK();

    return true;
  }

  BIC_SIMPLE_SET_RES(c_bi_class_integer,1);

  return true;
}/*}}}*/

bool bic_prolog_query_method_to_string_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  BIC_TO_STRING_WITHOUT_DEST(
    string_ptr->set(strlen("PrologQuery"),"PrologQuery");
  );

  return true;
}/*}}}*/

bool bic_prolog_query_method_print_0(interpreter_thread_s &it,unsigned stack_base,uli *operands)
{/*{{{*/
  printf("PrologQuery");

  BIC_SET_RESULT_BLANK();

  return true;
}/*}}}*/

