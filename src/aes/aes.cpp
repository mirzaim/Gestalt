/*
 * Copyright 2023-2024 The Gestalt Project Authors. All Rights Reserved.
 *
 * Licensed under the MIT License. See the file LICENSE for the full text.
 */

/*
 * aes.cpp
 *
 * This file contains the implementation of Gestalts AES security functions.
 */

#include <gestalt/aes.h>
#include "../aes/aesCore.h"
#include "../modes/modes.h"

std::string aesEncryptECB(std::string msg, std::string key) {
    return encryptECB<AES, unsigned char, 16, applyPCKS7Padding>(msg, key, &AES::encryptBlock);
}

std::string aesDecryptECB(std::string msg, std::string key) {
    return decryptECB<AES, unsigned char, 16, removePCKS7Padding>(msg, key, &AES::decryptBlock);
}

std::string aesEncryptCBC(std::string msg, std::string iv, std::string key) {
	return encryptCBC<AES, unsigned char, 16, applyPCKS7Padding>(msg, key, iv, &AES::encryptBlock);
}

std::string aesDecryptCBC(std::string msg, std::string iv, std::string key) {
	return decryptCBC<AES, unsigned char, 16, removePCKS7Padding>(msg, key, iv, &AES::decryptBlock);
}