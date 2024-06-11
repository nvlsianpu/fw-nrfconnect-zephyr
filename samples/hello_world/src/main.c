/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

int main(void)
{
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);
	atack_key();
	return 0;
}

#include "bl_storage.h"
#include <nrfx_nvmc.h>

void atack_key(void)
{
	const volatile uint32_t *invalidation_token =
			&BL_STORAGE->key_data[0].valid;

	/* Write if not already written. */
	nrfx_nvmc_word_write((uint32_t)invalidation_token, 0x0000FFFF);
	printf("invalidation token atack: 0x%#08x\n", (uint32_t)invalidation_token);
	while(1);
}