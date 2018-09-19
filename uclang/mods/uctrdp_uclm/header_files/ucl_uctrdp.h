
#ifndef __UCL_UCTRDP_H
#define __UCL_UCTRDP_H

@begin
include "script_parser.h"
@end

#include "ucf2.h"

using namespace Ucf2;

#include <uctrdp.h>

/*
 * definition of structure trdp_pd_address_s
 */

struct trdp_pd_address_s
{
  unsigned char scope;
  TRDP::IPx dst_host;
  TRDP::IPx src_host;
  TRDP::IPx src2_host;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure trdp_pd_port_s
 */

struct trdp_pd_port_s
{
  TRDP::PD::Port port;
  location_s *pd_location;
  TRDP::Handle pub_handle;
  TRDP::Handle sub_handle;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of structure trdp_pd_address_s
 */

inline void trdp_pd_address_s::init()
{/*{{{*/
}/*}}}*/

inline void trdp_pd_address_s::clear(interpreter_thread_s &it)
{/*{{{*/
  init();
}/*}}}*/

/*
 * inline methods of structure trdp_pd_port_s
 */

inline void trdp_pd_port_s::init()
{/*{{{*/
  pd_location = nullptr;
  pub_handle = TRDP::TRDP_NULL_HANDLE;
  sub_handle = TRDP::TRDP_NULL_HANDLE;
}/*}}}*/

inline void trdp_pd_port_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release pd location -
  if (pd_location != nullptr)
  {
    TRDP::PD *pd_ptr = (TRDP::PD *)pd_location->v_data_ptr;

    // - unpublish port -
    if (pub_handle != TRDP::TRDP_NULL_HANDLE)
    {
      // FIXME TODO remove cassert
      cassert(pd_ptr->Unpublish(pub_handle) == TRDP::TRDP_OK);
    }

    // - unsubscribe port -
    if (sub_handle != TRDP::TRDP_NULL_HANDLE)
    {
      // FIXME TODO remove cassert
      cassert(pd_ptr->Unsubscribe(sub_handle) == TRDP::TRDP_OK);
    }

    it.release_location_ptr(pd_location);
  }

  init();
}/*}}}*/

#endif

