/*
 * sdp_ctrl_client_config.h
 *
 *  Created on: Apr 11, 2016
 *      Author: hydrolucid3
 */

#ifndef SDP_CTRL_CLIENT_CONFIG_H_
#define SDP_CTRL_CLIENT_CONFIG_H_


#include "sdp_ctrl_client.h"
#include <sys/stat.h>
#include <openssl/ssl.h>
#include <openssl/crypto.h>
#include <openssl/err.h>

#define NANOS_PER_SECOND 1000000000

enum {
	SDP_MAX_SERVER_STR_LEN  = 50,
	SDP_MAX_LINE_LEN        = 1024,
	SDP_MAX_KEY_LEN         = 128,
	SDP_MAX_B64_KEY_LEN     = 180,
	SDP_MAX_MSG_Q_LEN       = 100,
	SDP_MAX_POST_SPA_DELAY  = 10
};

enum {
	DEFAULT_USE_SPA =0,
	DEFAULT_USE_SYSLOG=0,
	DEFAULT_REMAIN_CONNECTED =0,
	DEFAULT_FOREGROUND =1,
	DEFAULT_MAX_CONN_ATTEMPTS =3,
	DEFAULT_MAX_REQ_ATTEMPTS =3,
	DEFAULT_INTERVAL_REQ_RETRY_SECONDS =10,
	DEFAULT_INTERVAL_INITIAL_RETRY_SECONDS =5,
	DEFAULT_INTERVAL_CRED_UPDATE_SECONDS =7200,
	DEFAULT_INTERVAL_ACCESS_UPDATE_SECONDS =86400,
	DEFAULT_INTERVAL_KEEP_ALIVE_SECONDS =60,
	DEFAULT_MSG_Q_LEN=10,
	DEFAULT_POST_SPA_DELAY_NANOSECONDS=500000000,
	DEFAULT_POST_SPA_DELAY_SECONDS=0,
	DEFAULT_READ_TIMOUT_SECONDS =1,
	DEFAULT_WRITE_TIMOUT_SECONDS =1
};

// this must always be updated in conjunction with the
// config map in sdp_ctrl_client_config.c
enum {
	SDP_CTRL_CLIENT_CONFIG_CTRL_PORT = 0,
	SDP_CTRL_CLIENT_CONFIG_CTRL_ADDR,
	SDP_CTRL_CLIENT_CONFIG_USE_SPA,
	SDP_CTRL_CLIENT_CONFIG_CTRL_STANZA,
	SDP_CTRL_CLIENT_CONFIG_REMAIN_CONNECTED,
	SDP_CTRL_CLIENT_CONFIG_FOREGROUND,
	SDP_CTRL_CLIENT_CONFIG_USE_SYSLOG,
	SDP_CTRL_CLIENT_CONFIG_VERBOSITY,
	SDP_CTRL_CLIENT_CONFIG_KEY_FILE,
	SDP_CTRL_CLIENT_CONFIG_CERT_FILE,
	SDP_CTRL_CLIENT_CONFIG_SPA_ENCRYPTION_KEY,
	SDP_CTRL_CLIENT_CONFIG_SPA_HMAC_KEY,
	SDP_CTRL_CLIENT_CONFIG_MSG_Q_LEN,
	SDP_CTRL_CLIENT_CONFIG_POST_SPA_DELAY,
	SDP_CTRL_CLIENT_CONFIG_READ_TIMEOUT,
	SDP_CTRL_CLIENT_CONFIG_WRITE_TIMEOUT,
	SDP_CTRL_CLIENT_CONFIG_CRED_UPDATE_INTERVAL,
	SDP_CTRL_CLIENT_CONFIG_ACCESS_UPDATE_INTERVAL,
	SDP_CTRL_CLIENT_CONFIG_MAX_CONN_ATTEMPTS,
	SDP_CTRL_CLIENT_CONFIG_INIT_CONN_RETRY_INTERVAL,
	SDP_CTRL_CLIENT_CONFIG_KEEP_ALIVE_INTERVAL,
	SDP_CTRL_CLIENT_CONFIG_MAX_REQUEST_ATTEMPTS,
	SDP_CTRL_CLIENT_CONFIG_INIT_REQUEST_RETRY_INTERVAL,
	SDP_CTRL_CLIENT_CONFIG_PID_FILE,
	SDP_CTRL_CLIENT_CONFIG_ENTRIES
};



#define IS_EMPTY_LINE(x) ( \
    x == '#' || x == '\n' || x == '\r' || x == ';' || x == '\0' \
)



int sdp_ctrl_client_config_init(sdp_ctrl_client_t client, const char *config_file, const char *fwknoprc_file);
int sdp_ctrl_client_set_config_entry(sdp_ctrl_client_t client, int var, const char *val);
int sdp_ctrl_client_ssl_ctx_init(SSL_CTX **ssl_ctx);
int sdp_ctrl_client_load_certs(SSL_CTX* ctx, char* cert_file, char* key_file);

#endif /* SDP_CTRL_CLIENT_CONFIG_H_ */
