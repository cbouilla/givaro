// ==========================================================================
// $Source: /var/lib/cvs/Givaro/src/kernel/gmp++/gmp++_int_mul.C,v $
// Copyright(c)'1994-2009 by The Givaro group
// This file is part of Givaro.
// Givaro is governed by the CeCILL-B license under French law
// and abiding by the rules of distribution of free software.
// see the COPYRIGHT file for more details.
// Authors: M. Samama, T. Gautier
// $Id: gmp++_int_mul.C,v 1.11 2011-01-20 08:19:15 jgdumas Exp $
// ==========================================================================
/** @file gmp++/gmp++_int_mul.C
 * muling stuff.
 */

#ifndef __GIVARO_gmpxx_gmpxx_int_mul_C
#define __GIVARO_gmpxx_gmpxx_int_mul_C

#ifndef __GIVARO_INLINE_ALL
#include "gmp++/gmp++.h"
#endif

namespace Givaro {

//-------------------------------------------------- operator *
Integer& Integer::mulin(Integer& res, const Integer& n)
{
  if (isZero(n)) return res = Integer::zero;
  if (isZero(res)) return res;
  mpz_mul( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&n.gmp_rep );
  return res;
}
Integer& Integer::mulin(Integer& res, const int64_t n)
{
  if (isZero(n)) return res = Integer::zero;
  if (isZero(res)) return res;
//   int32_t sgn = sign(n);
  // int32_t sgn = sign(n);
  // mpz_mul_ui( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, abs(n));
//   if (sgn <0) res.gmp_rep.size = -res.gmp_rep.size;
  // if (sgn <0) return res = -res;
  mpz_mul_si( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, n);
  return res;
}
Integer& Integer::mulin(Integer& res, const uint64_t n)
{
  if (isZero(n)) return res = Integer::zero;
  if (isZero(res)) return res;
  mpz_mul_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&res.gmp_rep, n);
  return res;
}

Integer& Integer::mul(Integer& res, const Integer& n1, const Integer& n2)
{
  if (isZero(n1)) return res = Integer::zero;
  if (isZero(n2)) return res = Integer::zero;
  mpz_mul( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&n1.gmp_rep, (mpz_srcptr)&n2.gmp_rep);
  return res;
}
Integer& Integer::mul(Integer& res, const Integer& n1, const int64_t n2)
{
  if (isZero(n1)) return res = Integer::zero;
  if (isZero(n2)) return res = Integer::zero;
  // int32_t sgn = sign(n2);
  // mpz_mul_ui( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&n1.gmp_rep, abs(n2));
  // if (sgn <0) res.gmp_rep.size = -res.gmp_rep.size;
  // if (sgn <0) return res = -res;
  mpz_mul_si( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&n1.gmp_rep, n2);
  return res;
}
Integer& Integer::mul(Integer& res, const Integer& n1, const uint64_t n2)
{
  if (isZero(n1)) return res = Integer::zero;
  if (isZero(n2)) return res = Integer::zero;
  mpz_mul_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&n1.gmp_rep, n2);
  return res;
}

Integer& Integer::axpy(Integer& res, const Integer& a, const Integer& x, const Integer& b)
{
    if (&res == &b) return Integer::axpyin(res,a,x);
    if (isZero(a) || isZero(x)) return res = b;
	mpz_mul( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, (mpz_srcptr)&x.gmp_rep);
	mpz_add( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&b.gmp_rep);
    return res;
}

Integer& Integer::axpy(Integer& res, const Integer& a, const uint64_t x, const Integer& b)
{
    if (&res == &b) return Integer::axpyin(res,a,x);
    if (isZero(a) || isZero(x)) return res = b;
	mpz_mul_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, x);
	mpz_add( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&b.gmp_rep);
    return res;
}


Integer& Integer::axpyin(Integer& res, const Integer& a, const Integer& x)
{
    if (isZero(a) || isZero(x)) return res;
    mpz_addmul( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, (mpz_srcptr)&x.gmp_rep);
    return res;
}

Integer& Integer::axpyin(Integer& res, const Integer& a, const uint64_t x)
{
    if (isZero(a) || isZero(x)) return res;
    mpz_addmul_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, x);
    return res;
}


Integer& Integer::maxpy(Integer& res, const Integer& a, const Integer& x, const Integer& b)
{
    if (isZero(a) || isZero(x)) return res=b;
    if (&res == &b) return Integer::maxpyin(res,a,x);
    mpz_mul( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, (mpz_srcptr)&x.gmp_rep);
    mpz_sub( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&b.gmp_rep, (mpz_ptr)&res.gmp_rep);
	return res;
}
Integer& Integer::maxpy(Integer& res, const Integer& a, const uint64_t x, const Integer& b)
{
    if (isZero(a) || isZero(x)) return res=b;
    if (&res == &b) return Integer::maxpyin(res,a,x);
    mpz_mul_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, x);
    mpz_sub( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&b.gmp_rep, (mpz_ptr)&res.gmp_rep);
	return res;
}

Integer& Integer::axmy(Integer& res, const Integer& a, const Integer& x, const Integer& b)
{
    if (&res == &b) return Integer::axmyin(res,a,x);
    if (isZero(a) || isZero(x)) return Integer::neg(res,b);
    mpz_mul( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, (mpz_srcptr)&x.gmp_rep);
    mpz_sub( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&b.gmp_rep);
    return res;
}

Integer& Integer::axmy(Integer& res, const Integer& a, const uint64_t x, const Integer& b)
{
    if (&res == &b) return Integer::axmyin(res,a,x);
    if (isZero(a) || isZero(x)) return Integer::neg(res,b);
    mpz_mul_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, x);
    mpz_sub( (mpz_ptr)&res.gmp_rep, (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&b.gmp_rep);
    return res;
}

Integer& Integer::axmyin(Integer& res, const Integer& a, const Integer& x)
{
	Integer::maxpyin(res,a,x);
	Integer::negin(res);
	return res ;
}

Integer& Integer::axmyin(Integer& res, const Integer& a, const uint64_t x)
{
	Integer::maxpyin(res,a,x);
	Integer::negin(res);
	return res ;
}

Integer& Integer::maxpyin(Integer& res, const Integer& a, const Integer& x)
{
    if (isZero(a) || isZero(x)) return res;
    mpz_submul( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, (mpz_srcptr)&x.gmp_rep);
    return res;
}

Integer& Integer::maxpyin(Integer& res, const Integer& a, const uint64_t x)
{
    if (isZero(a) || isZero(x)) return res;
    mpz_submul_ui( (mpz_ptr)&res.gmp_rep, (mpz_srcptr)&a.gmp_rep, x);
    return res;
}

Integer& Integer::operator *= (const Integer& n)
{
  if (isZero(n)) return *this = Integer::zero;
  if (isZero(*this)) return *this;
//   Rep (res.gmp_rep)( MAX(SZ_REP(n.gmp_rep),SZ_REP(gmp_rep)) );
  Integer res;
  mpz_mul( (mpz_ptr)&(res.gmp_rep), (mpz_ptr)&gmp_rep, (mpz_srcptr)&n.gmp_rep) ;
  return *this = res;
}

Integer& Integer::operator *= (const uint64_t l)
{
  if (l==0) return *this = Integer::zero;
  if (isZero(*this)) return *this;
//   Rep (res.gmp_rep)( MAX(SZ_REP(gmp_rep),1) );
  mpz_mul_ui( (mpz_ptr)&(gmp_rep), (mpz_ptr)&gmp_rep, l);
  return *this;
}

Integer& Integer::operator *= (const int64_t l)
{
  if (l==0) return *this =Integer::zero;
  if (isZero(*this)) return *this;
//   Rep (res.gmp_rep)( MAX(SZ_REP(gmp_rep),1) );
  // int32_t sgn = sign(l);
  // mpz_mul_ui( (mpz_ptr)&(gmp_rep), (mpz_ptr)&gmp_rep, abs(l));
  // if (sgn <0) mpz_neg( (mpz_ptr)&gmp_rep, (mpz_ptr)&(gmp_rep) );
  mpz_mul_si( (mpz_ptr)&(gmp_rep), (mpz_ptr)&gmp_rep, l);
  return *this;
}


Integer Integer::operator * (const Integer& n) const
{
  if (isZero(n)) return Integer::zero;
  if (isZero(*this)) return Integer::zero;
//   Rep (res.gmp_rep)( MAX(SZ_REP(n.gmp_rep),SZ_REP(gmp_rep)) );
  Integer res;
  mpz_mul( (mpz_ptr)&(res.gmp_rep), (mpz_srcptr)&gmp_rep, (mpz_srcptr)&n.gmp_rep) ;
  return res;
}

Integer Integer::operator * (const uint64_t l) const
{
  if (l==0) return Integer::zero;
  if (isZero(*this)) return Integer::zero;
//   Rep (res.gmp_rep)( MAX(SZ_REP(gmp_rep),1) );
  Integer res;
  mpz_mul_ui( (mpz_ptr)&(res.gmp_rep), (mpz_srcptr)&gmp_rep, l);
  return res;
}

Integer Integer::operator * (const int64_t l) const
{
  if (l==0) return Integer::zero;
  if (isZero(*this)) return Integer::zero;
//   Rep (res.gmp_rep)( MAX(SZ_REP(gmp_rep),1) );
  Integer res;
  // int32_t sgn = sign(l);
  // mpz_mul_ui( (mpz_ptr)&(res.gmp_rep), (mpz_ptr)&gmp_rep, abs(l));
//   if (sgn <0) (res.gmp_rep).size = -(res.gmp_rep).size;
//   return Integer((res.gmp_rep));
  // if (sgn <0) mpz_neg( (mpz_ptr)&(res.gmp_rep), (mpz_ptr)&(res.gmp_rep) );
  mpz_mul_si( (mpz_ptr)&(res.gmp_rep), (mpz_srcptr)&gmp_rep, l);
  return res;
}

	// -- operator *
	 Integer operator * (const int32_t l, const Integer& n)
	{
		return n * (int64_t)l;
	}
	 Integer operator * (const uint32_t l, const Integer& n)
	{
		return n * (uint64_t)l;
	}
	 Integer operator * (const int64_t l, const Integer& n)
	{
		return n * l;
	}
	 Integer operator * (const uint64_t l, const Integer& n)
	{
		return n * l;
	}



}
#endif // __GIVARO_gmpxx_gmpxx_int_mul_C
// vim:sts=8:sw=8:ts=8:noet:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s
