/*
 * Copyright 2023-2024 The Gestalt Project Authors. All Rights Reserved.
 *
 * Licensed under the MIT License. See the file LICENSE for the full text.
 */

/*
 * ecdsa.h
 *
 * This file contains the definitions of Gestalts ECDSA security functions.
 */

#pragma once

#include <string>

#include "../src/ecc/ecc.h"

class ECDSA {
private:

    ECC ecc;

    void prepareMessage(const std::string& message, mpz_t& result);
    void fieldElementToInteger(const mpz_t& fieldElement, const mpz_t& modulus, mpz_t result);

    Signature generateSignature(const mpz_t& e, const KeyPair& keyPair, mpz_t& k);
public:
    KeyPair keyPair;

    ECDSA(StandardCurve curve = StandardCurve::secp256k1) : ecc(curve) {
        // Initialize ECDSA with the selected standard curve
        this->keyPair = generateKeyPair();
    }
	~ECDSA() {}

    KeyPair generateKeyPair();
    KeyPair setKeyPair(const std::string& strKey);
    Signature signMessage(const std::string& message, const KeyPair& keyPair);
    Signature signMessage(const std::string& message, const KeyPair& keyPair, mpz_t& k);
    bool verifySignature(const std::string& message, const Signature signature, const Point& publicKey);
};