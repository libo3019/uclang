
#ifndef __UCL_CRYPTO_H
#define __UCL_CRYPTO_H

@begin
include "script_parser.h"
@end

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>

const char c_base16_map[] = "0123456789abcdef";

/*
 * definition of class crypto_c
 */
class crypto_c
{
  public:
  inline crypto_c();
  inline ~crypto_c();
};

/*
 * definition of structure crypto_digest_s
 */

struct crypto_digest_s
{
  EVP_MD_CTX *context;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * definition of structure crypto_cipher_s
 */

struct crypto_cipher_s
{
  EVP_CIPHER_CTX *context;

  inline void init();
  inline void clear(interpreter_thread_s &it);
};

/*
 * inline methods of class crypto_c
 */

inline crypto_c::crypto_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libcrypto_init()\n"););

  ERR_load_crypto_strings();
  OpenSSL_add_all_algorithms();
}/*}}}*/

inline crypto_c::~crypto_c()
{/*{{{*/
  debug_message_2(fprintf(stderr,"libcrypto_exit()\n"););

  EVP_cleanup();
  CRYPTO_cleanup_all_ex_data();
  ERR_free_strings();
}/*}}}*/

/*
 * inline methods of structure crypto_digest_s
 */

inline void crypto_digest_s::init()
{/*{{{*/
  context = nullptr;
}/*}}}*/

inline void crypto_digest_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release crypto digest context -
  if (context != nullptr)
  {
    EVP_MD_CTX_destroy(context);
  }

  init();
}/*}}}*/

/*
 * inline methods of structure crypto_cipher_s
 */

inline void crypto_cipher_s::init()
{/*{{{*/
  context = nullptr;
}/*}}}*/

inline void crypto_cipher_s::clear(interpreter_thread_s &it)
{/*{{{*/

  // - release crypto cipher context -
  if (context != nullptr)
  {
    EVP_CIPHER_CTX_free(context);
  }

  init();
}/*}}}*/

#endif

