
#ifndef __UCL_CHANNEL_H
#define __UCL_CHANNEL_H

@begin
include "script_parser.h"
@end

#include <netdb.h>
#include <poll.h>
#include <sys/ioctl.h>

/*
 * basic definitions and constants
 */

extern unsigned c_bi_class_channel_server;
extern unsigned c_bi_class_channel_client;

#define CHANNEL_CALL_CALLBACK_DELEGATE(NAME,SOURCE_POS,PARAM_CODE,ERROR_CODE) \
{/*{{{*/\
  delegate_s *delegate_ptr = (delegate_s *)((location_s *)NAME)->v_data_ptr;\
\
  PARAM_CODE;\
\
  /* - call delegate method - */\
  location_s *trg_location = nullptr;\
  BIC_CALL_DELEGATE(it,delegate_ptr,param_data,param_cnt,trg_location,SOURCE_POS,\
    ERROR_CODE;\
  );\
  it.release_location_ptr(trg_location);\
}/*}}}*/

/*
 * definition of generated structures
 */

// -- fd_conn_map_s --
@begin
struct
<
bi:fd
ui:conn_index
>
fd_conn_map_s;
@end

// -- fd_conn_map_tree_s --
@begin
safe_rb_tree<fd_conn_map_s> fd_conn_map_tree_s;
@end

// -- channel_conn_s --
@begin
struct
<
bi:conn_fd
ui:events
bool:connecting

pointer:event_callback
pointer:message_callback
pointer:user_data
ui:conn_index

bc_array_s:in_msg
ui:in_msg_length

pointer_queue_s:out_msg_queue
ui:out_msg_offset
>

additions
{
  bool send_msg(interpreter_thread_s &it);
  bool recv_msg(interpreter_thread_s &it,location_s *dst_location,unsigned a_source_pos);

  inline void init_static();
  inline void clear(interpreter_thread_s &it);
}

channel_conn_s;
@end

// -- channel_conn_list_s --
@begin
safe_list<channel_conn_s> channel_conn_list_s;
@end

// -- channel_server_s --
@begin
struct
<
bi:server_fd
pointer:new_callback
pointer:drop_callback
pointer:message_callback
pointer:user_data
channel_conn_list_s:conn_list
fd_conn_map_tree_s:fd_conn_map
>

additions
{
  inline void init_static();
  inline void clear(interpreter_thread_s &it);
}

channel_server_s;
@end

/*
 * inline methods of generated structures
 */

// -- fd_conn_map_s --
@begin
inlines fd_conn_map_s
@end

// -- fd_conn_map_tree_s --
@begin
inlines fd_conn_map_tree_s
@end

inline int fd_conn_map_tree_s::__compare_value(fd_conn_map_s &a_first,fd_conn_map_s &a_second)
{/*{{{*/
  return a_first.fd < a_second.fd ? -1 : a_first.fd > a_second.fd ? 1 : 0;
}/*}}}*/

// -- channel_conn_s --
@begin
inlines channel_conn_s
@end

inline void channel_conn_s::init_static()
{/*{{{*/
  conn_fd = -1;
  events = 0;
  connecting = false;

  event_callback = nullptr;
  message_callback = nullptr;
  user_data = nullptr;
  conn_index = c_idx_not_exist;

  in_msg_length = 0;
  out_msg_offset = 0;
}/*}}}*/

inline void channel_conn_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (conn_fd != -1)
  {
    close(conn_fd);
  }

  if (event_callback != nullptr)
  {
    it.release_location_ptr((location_s *)event_callback);
  }

  if (message_callback != nullptr)
  {
    it.release_location_ptr((location_s *)message_callback);
  }

  if (user_data != nullptr)
  {
    it.release_location_ptr((location_s *)user_data);
  }

  // - release not send output messages  -
  while (out_msg_queue.used != 0)
  {
    it.release_location_ptr((location_s *)out_msg_queue.next());
  }

  clear();
  init_static();
}/*}}}*/

// -- channel_conn_list_s --
@begin
inlines channel_conn_list_s
@end

// -- channel_server_s --
@begin
inlines channel_server_s
@end

inline void channel_server_s::init_static()
{/*{{{*/
  server_fd = -1;
  new_callback = nullptr;
  drop_callback = nullptr;
  message_callback = nullptr;
  user_data = nullptr;
}/*}}}*/

inline void channel_server_s::clear(interpreter_thread_s &it)
{/*{{{*/
  if (server_fd != -1)
  {
    close(server_fd);
  }

  // - release callbacks -
  if (new_callback != nullptr)
  {
    it.release_location_ptr((location_s *)new_callback);
  }

  if (drop_callback != nullptr)
  {
    it.release_location_ptr((location_s *)drop_callback);
  }

  if (message_callback != nullptr)
  {
    it.release_location_ptr((location_s *)message_callback);
  }

  // - release user data -
  if (user_data != nullptr)
  {
    it.release_location_ptr((location_s *)user_data);
  }

  // - release channel connections -
  if (conn_list.first_idx != c_idx_not_exist)
  {
    unsigned cl_idx = conn_list.first_idx;
    do {
      conn_list[cl_idx].clear(it);

      cl_idx = conn_list.next_idx(cl_idx);
    } while(cl_idx != c_idx_not_exist);
  }

  clear();
  init_static();
}/*}}}*/

#endif

