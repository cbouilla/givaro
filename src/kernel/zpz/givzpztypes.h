// ==========================================================================
// $Source: /var/lib/cvs/Givaro/src/kernel/zpz/givzpztypes.h,v $
// Copyright(c)'1994-2011 by The Givaro group
// Time-stamp: <02 Feb 11 14:36:21 Jean-Guillaume.Dumas@imag.fr>        //
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: JG Dumas
// ==========================================================================

/*! @file zpz/givzpztypes.h
 * @ingroup zpz
 * @brief  Family of types for arithmetic over Zpz.
 */

#ifndef __GIVARO_zpztypes_H
#define __GIVARO_zpztypes_H

// ==========================================================================
// --
// ==========================================================================
#include <givaro/givconfig.h>

namespace Givaro {

template<class TAG> class ZpzDom;

// -- Tag for arithmetic:
struct Std16 { typedef int16_t type;}; // -- standard arithmetic over 16bits representations.
struct Std32 { typedef int32_t type;}; // -- standard arithmetic over 32bits representations.
struct Unsigned32 {typedef uint32_t  type;}; // -- standard arithmetic over 32bits representations.

struct Log16 { typedef int16_t type;}; // -- log arithmetic over 16bits representations.

#ifndef __DONOTUSE_Givaro_SIXTYFOUR__
struct Std64 { typedef int64_t type;}; // -- standard arithmetic over 64bits representations.
#endif

}

#endif // __GIVARO_zpztypes_H
