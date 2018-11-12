#ifndef _DAP_ENC_BASE64_H_
#define _DAP_ENC_BASE64_H_
#include <stddef.h>
#include "dap_enc_key.h"
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Calculates encode size from input size
 */
#define DAP_ENC_BASE64_ENCODE_SIZE(in_size) (size_t)(((4 * in_size / 3) + 3) & ~3)

size_t dap_enc_base64_decode(const char * in, size_t in_size, void * out, dap_enc_data_type_t standard);
size_t dap_enc_base64_encode(const void * in, size_t in_size, char * out, dap_enc_data_type_t standard);

#ifdef __cplusplus
}
#endif

#endif
