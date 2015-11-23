
#ifndef __UCL_BINBITS_H
#define __UCL_BINBITS_H

@begin
include "script_parser.h"
@end

// - bin array types -
enum
{
  c_bin_array_type_int32,
  c_bin_array_type_uint32,
};

/*
 * definition of structure bin_array_ref_s
 */

struct bin_array_ref_s
{
  location_s *ba_location;
  unsigned index;
};

/*
 * definition of structure bin_array_s
 */

struct bin_array_s
{
  unsigned type;
  void *cont;
  pointer_array_s free_references;

  inline void init();
  inline void clear(interpreter_thread_s &it);

  inline bin_array_ref_s *create_reference(location_s *ba_location,unsigned index);
  inline void release_reference(interpreter_thread_s &it,bin_array_ref_s *bar_ptr);
};

/*
 * inline methods of structure bin_array_s
 */

inline void bin_array_s::init()
{/*{{{*/
  cont = NULL;
  free_references.init();
}/*}}}*/

inline void bin_array_s::clear(interpreter_thread_s &it)
{/*{{{*/
  
  if (cont != NULL)
  {
    switch (type)
    {
    case c_bin_array_type_int32:
      ((bi_array_s *)cont)->clear();
      break;
    case c_bin_array_type_uint32:
      ((ui_array_s *)cont)->clear();
      break;
    default:
      cassert(0);
    }

    cfree(cont);
  }

  // - release bin array references -
  if (free_references.used > 0)
  {
    pointer *r_ptr = free_references.data;
    pointer *r_ptr_end = r_ptr + free_references.used;
    do {
      cfree(*r_ptr);
    } while(++r_ptr < r_ptr_end);
  }

  free_references.clear();

  init();
}/*}}}*/

inline bin_array_ref_s *bin_array_s::create_reference(location_s *ba_location,unsigned index)
{/*{{{*/
  bin_array_ref_s *bar_ptr;

  // - if there are some existing references -
  if (free_references.used > 0)
  {
    // - reuse existing reference -
    bar_ptr = (bin_array_ref_s *)free_references.pop();
  }
  else
  {
    // - create new reference -
    bar_ptr = (bin_array_ref_s *)cmalloc(sizeof(bin_array_ref_s));
  }

  ba_location->v_reference_cnt.atomic_inc();
  bar_ptr->ba_location = ba_location;
  bar_ptr->index = index;

  return bar_ptr;
}/*}}}*/

inline void bin_array_s::release_reference(interpreter_thread_s &it,bin_array_ref_s *bar_ptr)
{/*{{{*/
  
  // - store released reference -
  free_references.push(bar_ptr);

  it.release_location_ptr(bar_ptr->ba_location);
}/*}}}*/

#endif

