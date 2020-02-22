/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:44:50 by rkergast          #+#    #+#             */
/*   Updated: 2020/02/22 16:51:29 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void SetGlyph(int x, int y, wchar_t c)
{
	if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
		return;
	else
		m_Glyphs[y * nWidth + x] = c;
}

void SetColour(int x, int y, short c)
{
	if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
		return;
	else
		m_Colours[y * nWidth + x] = c;
}

wchar_t GetGlyph(int x, int y)
{
	if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
		return L' ';
	else
		return m_Glyphs[y * nWidth + x];
}

short GetColour(int x, int y)
{
	if (x < 0 || x >= nWidth || y < 0 || y >= nHeight)
		return FG_BLACK;
	else
		return m_Colours[y * nWidth + x];
}

wchar_t SampleGlyph(float x, float y)
{
	int sx = (int)(x * (float)nWidth);
	int sy = (int)(y * (float)nHeight - 1.0f);
	if (sx < 0 || sx >= nWidth || sy < 0 || sy >= nHeight)
		return L' ';
	else
		return m_Glyphs[sy * nWidth + sx];
}

short SampleColour(float x, float y)
{
	int sx = (int)(x * (float)nWidth);
	int sy = (int)(y * (float)nHeight - 1.0f);
	if (sx < 0 || sx >= nWidth || sy < 0 || sy >= nHeight)
		return FG_BLACK;
	else
		return m_Colours[sy * nWidth + sx];
}
