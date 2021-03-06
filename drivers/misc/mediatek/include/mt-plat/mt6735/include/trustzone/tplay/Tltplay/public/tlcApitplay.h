/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef TLTPLAY_H_
#define TLTPLAY_H_

#include "tci.h"

/*
 * Command ID's for communication Trustlet Connector -> Trustlet.
 */
#define CMD_TPLAY_REQUEST   4
#define CMD_TPLAY_DUMP_PHY  5
#define CMD_TPLAY_TEST      6



/*
 * Termination codes
 */
#define EXIT_ERROR                  ((uint32_t)(-1))

/*
 * command message.
 *
 * @param len Length of the data to process.
 * @param data Data to processed (cleartext or ciphertext).
 */
typedef struct {
		tciCommandHeader_t  header;     /**< Command header */
		uint32_t            len;        /**< Length of data to process or buffer */
		uint32_t            respLen;    /**< Length of response buffer */
} tplay_cmd_t;

/*
 * Response structure Trustlet -> Trustlet Connector.
 */
typedef struct {
		tciResponseHeader_t header;     /**< Response header */
		uint32_t            len;
} tplay_rsp_t;

/*
 * TCI message data.
 */
typedef struct {
		union {
				tplay_cmd_t     cmd;
				tplay_rsp_t     rsp;
		};
		uint32_t    index;
		uint32_t    result;
		uint32_t    data_addr;
		uint32_t    data_len;
		uint32_t    seed_addr;
		uint32_t    seed_len;
		uint32_t    hacc_user;
		uint32_t    direction;
		uint32_t    tplay_handle_low_addr;
		uint32_t    tplay_handle_high_addr;
} tplay_tciMessage_t;

/*
 * Trustlet UUID.
 */
/* 05200000000000000000000000000000 */
#define TL_TPLAY_UUID {{0, 5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} }

#endif /* TLFOO_H_ */
