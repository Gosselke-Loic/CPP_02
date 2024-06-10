/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosselk <lgosselk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:34:00 by lgosselk          #+#    #+#             */
/*   Updated: 2024/04/04 10:09:04 by lgosselk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	mpow(float base, float exp){

    if (exp == 0) {
        return (1);
    } else if (exp < 0) {
        return (1 / mpow(base, -exp));
    } else if ((int)exp % 2 == 0) {
        float half_pow = mpow(base, exp/2);
        return (half_pow * half_pow);
    } else {
        return (base * pow(base, exp - 1));
    }
}

static float	msqrt(float a)
{
    int i;
    for (i = 0;i * i <= a;i++);
    
    float lb = i - 1; 
    if (lb * lb == a)
        return (lb);
    float ub = lb + 1; 
    float pub = ub;
    for (int j = 0;j <= 20;j++)
    {
        float ub2 = ub * ub;
        if (ub2 > a) {
            pub = ub;
            ub = (lb + ub) / 2;
        } else {
            lb = ub;
            ub = pub;
        }
    }
    return (ub);
}

static Fixed	abs( Fixed x ) {
	if (x < 0)
		return (x * -1);
	return (x);
}

static float limits( const Point v1, const Point v2, const Point v3 ) {
	
	float	seg1 = msqrt(mpow((v2.getX().toFloat() - v1.getX().toFloat()), 2)
		+ mpow((v2.getY().toFloat() - v1.getY().toFloat()), 2));
	float	seg2 = msqrt(mpow((v3.getX().toFloat() - v2.getX().toFloat()), 2)
		+ mpow((v3.getY().toFloat() - v2.getY().toFloat()), 2));

	return (seg1 + seg2);
}

static Fixed	area(  const Point v1, const Point v2, const Point v3 ) {
	return (( ( v1.getX() * (v2.getY() - v3.getY()) )
		+ ( v2.getX() * (v3.getY() - v1.getY()) )
		+ ( v3.getX() * (v1.getY() - v2.getY()) ) ) / 2);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point ) {

	float	segAB = msqrt(mpow((b.getX().toFloat() - a.getX().toFloat()), 2)
		+ mpow((b.getY().toFloat() - a.getY().toFloat()), 2));
	float	segBC = msqrt(mpow((c.getX().toFloat() - b.getX().toFloat()), 2)
		+ mpow((c.getY().toFloat() - b.getY().toFloat()), 2));
	float	segAC = msqrt(mpow((c.getX().toFloat() - a.getX().toFloat()), 2)
		+ mpow((c.getY().toFloat() - a.getY().toFloat()), 2));

	if (segAB == limits(a, point, b) || segBC == limits(b, point, c) || segAC == limits(a, point, c)) {
		return (false);
	} else {
		Fixed	totalArea = abs( area(a, b, c) );
		Fixed	pbcArea = abs( area(point, a, b) );
		Fixed	apcArea = abs( area(point, b, c) );
		Fixed	abpArea = abs( area(point, c, a) );
		return ( totalArea == pbcArea + apcArea + abpArea );
	}
	return (false);
}