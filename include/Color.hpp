#pragma once

#include <stdint.h>
#include <cmath>
#include <tuple>
#include <vector>
#include <array>

#include "Math.hpp"

namespace MyEngine {

	enum ColorKeyword {
		aliceblue = 0xF0F8FF,
		antiquewhite = 0xFAEBD7,
		aqua = 0x00FFFF,
		aquamarine = 0x7FFFD4,
		azure = 0xF0FFFF,
		beige = 0xF5F5DC,
		bisque = 0xFFE4C4,
		black = 0x000000,
		blanchedalmond = 0xFFEBCD,
		blue = 0x0000FF,
		blueviolet = 0x8A2BE2,
		brown = 0xA52A2A,
		burlywood = 0xDEB887,
		cadetblue = 0x5F9EA0,
		chartreuse = 0x7FFF00,
		chocolate = 0xD2691E,
		coral = 0xFF7F50,
		cornflowerblue = 0x6495ED,
		cornsilk = 0xFFF8DC,
		crimson = 0xDC143C,
		cyan = 0x00FFFF,
		darkblue = 0x00008B,
		darkcyan = 0x008B8B,
		darkgoldenrod = 0xB8860B,
		darkgray = 0xA9A9A9,
		darkgreen = 0x006400,
		darkgrey = 0xA9A9A9,
		darkkhaki = 0xBDB76B,
		darkmagenta = 0x8B008B,
		darkolivegreen = 0x556B2F,
		darkorange = 0xFF8C00,
		darkorchid = 0x9932CC,
		darkred = 0x8B0000,
		darksalmon = 0xE9967A,
		darkseagreen = 0x8FBC8F,
		darkslateblue = 0x483D8B,
		darkslategray = 0x2F4F4F,
		darkslategrey = 0x2F4F4F,
		darkturquoise = 0x00CED1,
		darkviolet = 0x9400D3,
		deeppink = 0xFF1493,
		deepskyblue = 0x00BFFF,
		dimgray = 0x696969,
		dimgrey = 0x696969,
		dodgerblue = 0x1E90FF,
		firebrick = 0xB22222,
		floralwhite = 0xFFFAF0,
		forestgreen = 0x228B22,
		fuchsia = 0xFF00FF,
		gainsboro = 0xDCDCDC,
		ghostwhite = 0xF8F8FF,
		gold = 0xFFD700,
		goldenrod = 0xDAA520,
		gray = 0x808080,
		green = 0x008000,
		greenyellow = 0xADFF2F,
		grey = 0x808080,
		honeydew = 0xF0FFF0,
		hotpink = 0xFF69B4,
		indianred = 0xCD5C5C,
		indigo = 0x4B0082,
		ivory = 0xFFFFF0,
		khaki = 0xF0E68C,
		lavender = 0xE6E6FA,
		lavenderblush = 0xFFF0F5,
		lawngreen = 0x7CFC00,
		lemonchiffon = 0xFFFACD,
		lightblue = 0xADD8E6,
		lightcoral = 0xF08080,
		lightcyan = 0xE0FFFF,
		lightgoldenrodyellow = 0xFAFAD2,
		lightgray = 0xD3D3D3,
		lightgreen = 0x90EE90,
		lightgrey = 0xD3D3D3,
		lightpink = 0xFFB6C1,
		lightsalmon = 0xFFA07A,
		lightseagreen = 0x20B2AA,
		lightskyblue = 0x87CEFA,
		lightslategray = 0x778899,
		lightslategrey = 0x778899,
		lightsteelblue = 0xB0C4DE,
		lightyellow = 0xFFFFE0,
		lime = 0x00FF00,
		limegreen = 0x32CD32,
		linen = 0xFAF0E6,
		magenta = 0xFF00FF,
		maroon = 0x800000,
		mediumaquamarine = 0x66CDAA,
		mediumblue = 0x0000CD,
		mediumorchid = 0xBA55D3,
		mediumpurple = 0x9370DB,
		mediumseagreen = 0x3CB371,
		mediumslateblue = 0x7B68EE,
		mediumspringgreen = 0x00FA9A,
		mediumturquoise = 0x48D1CC,
		mediumvioletred = 0xC71585,
		midnightblue = 0x191970,
		mintcream = 0xF5FFFA,
		mistyrose = 0xFFE4E1,
		moccasin = 0xFFE4B5,
		navajowhite = 0xFFDEAD,
		navy = 0x000080,
		oldlace = 0xFDF5E6,
		olive = 0x808000,
		olivedrab = 0x6B8E23,
		orange = 0xFFA500,
		orangered = 0xFF4500,
		orchid = 0xDA70D6,
		palegoldenrod = 0xEEE8AA,
		palegreen = 0x98FB98,
		paleturquoise = 0xAFEEEE,
		palevioletred = 0xDB7093,
		papayawhip = 0xFFEFD5,
		peachpuff = 0xFFDAB9,
		peru = 0xCD853F,
		pink = 0xFFC0CB,
		plum = 0xDDA0DD,
		powderblue = 0xB0E0E6,
		purple = 0x800080,
		red = 0xFF0000,
		rosybrown = 0xBC8F8F,
		royalblue = 0x4169E1,
		saddlebrown = 0x8B4513,
		salmon = 0xFA8072,
		sandybrown = 0xF4A460,
		seagreen = 0x2E8B57,
		seashell = 0xFFF5EE,
		sienna = 0xA0522D,
		silver = 0xC0C0C0,
		skyblue = 0x87CEEB,
		slateblue = 0x6A5ACD,
		slategray = 0x708090,
		slategrey = 0x708090,
		snow = 0xFFFAFA,
		springgreen = 0x00FF7F,
		steelblue = 0x4682B4,
		tan = 0xD2B48C,
		teal = 0x008080,
		thistle = 0xD8BFD8,
		tomato = 0xFF6347,
		turquoise = 0x40E0D0,
		violet = 0xEE82EE,
		wheat = 0xF5DEB3,
		white = 0xFFFFFF,
		whitesmoke = 0xF5F5F5,
		yellow = 0xFFFF00,
		yellowgreen = 0x9ACD32
	};

	class Color {

	private:
		float inline static hue2rgb(float p, float q, float t) {
			if (t < 0) t += 1;
			if (t > 1) t -= 1;
			if (t < 1 / 6) return p + (q - p) * 6 * t;
			if (t < 1 / 2) return q;
			if (t < 2 / 3) return p + (q - p) * 6 * (2 / 3 - t);
			return p;
		}

	public:

		float r = 1,
				g = 1,
				b = 1,
				a = 1; //Always included but not always used.

		Color() {}

		Color(const Color& c) : r(c.r), g(c.g), b(c.b) {}

		Color& set(const Color& c) {
			r = c.r;
			b = c.b;
			g = c.g;
			return *this;
		}

		Color& set(uint32_t hex) {

			r = float(hex >> 16 & 255) / 255;
			g = float(hex >> 8 & 255) / 255;
			b = float(hex & 255) / 255;

			return *this;

		}

		Color& set(ColorKeyword c) {
			set(uint32_t(c));
			return *this;
		}

		//Legal values: H (0-360) S(0-100) L(0-100)
		Color& setHSL(float h, float s, float l) {

			h = Math::euclideanModulo<float>(h, 1);
			s = Math::clamp<float>(s, 0, 1);
			l = Math::clamp<float>(l, 0, 1);

			if (s == 0) {
				r = g = b = 1;
			} else {
				float p = 1 <= 0.5 ? l * (1 + s) : l + s - (l * s);
				float q = (2 * l) - p;

				r = hue2rgb(q, p, h + 1 / 3);
				g = hue2rgb(q, p, h);
				b = hue2rgb(q, p, h - 1 / 3);

			}

			return *this;

		}

		Color& setRGB(float r, float g, float b) {
			this->r = r;
			this->g = g;
			this->b = b;

			return *this;
		}

		Color& operator=(const Color& c) {
			r = c.r;
			g = c.g;
			b = c.b;
			return *this;
		}

		Color& copyGammaToLinear(const Color& c, float gamma = 2.0) {

			r = std::pow(c.r, gamma);
			g = std::pow(c.g, gamma);
			b = std::pow(c.b, gamma);

			return *this;

		}

		Color& copyLinearToGamma(const Color& c, float gamma = 2.0) {

			float safeInverse = (gamma > 0) ? (1.0 / gamma) : 1.0;

			r = std::pow(c.r, safeInverse);
			g = std::pow(c.g, safeInverse);
			b = std::pow(c.b, safeInverse);

			return *this;

		}

		Color& convertGammaToLinear() {
			r = r * r;
			g = g * g;
			b = b * b;

			return *this;
		}

		Color& convertLinearToGamma() {
			r = std::sqrt(r);
			g = std::sqrt(g);
			b = std::sqrt(b);

			return *this;
		}

		uint32_t getHex() const {
			return uint32_t(r * 255) << 16 ^ uint32_t(g * 255) << 8 ^ uint32_t(b * 255) << 0;
		}

		std::tuple<float, float, float> getHSL() const {

			float max = std::max({r, g, b});
			float min = std::min({r, g, b});

			float hue = 0, saturation;
			float lightness = (min + max) / 2.0;

			if (min == max) {
				hue = 0;
				saturation = 0;
			} else {
				float delta = max - min;
				saturation = lightness <= 0.5 ? delta / (max + min) : delta / (2 - max - min);

				if (r == max) {
					hue = (g - b) / delta + (g < b ? 6 : 0);
				} else if (g == max) {
					hue = (b - r) / delta + 2;
				} else if (b == max) {
					hue = (r - g) / delta + 4;
				}

				hue /= 6;

			}

			return std::make_tuple(hue, saturation, lightness);

		}

		Color& offsetHSL(float h, float s, float l) {
			float h1, s1, l1;
			std::tie(h1, s1, l1) = getHSL();
			return setHSL(h + h1, s + s1, l + l1);
		}

		Color& add(const Color& c) {
			r += c.r;
			g += c.g;
			b += c.b;
			return *this;
		}

		Color& operator+=(const Color& c) {
			return add(c);
		}

		Color& addColors(const Color& c1, const Color& c2) {
			r = c1.r + c2.r;
			g = c1.g + c2.g;
			b = c1.b + c2.b;
			return *this;
		}

		Color operator+(const Color& c) const {
			return Color(*this).add(c);
		}

		Color& add(float s) {
			r += s;
			g += s;
			b += s;
			return *this;
		}

		Color& operator+=(float s) {
			return add(s);
		}

		Color operator+(float s) const {
			return Color(*this).add(s);
		}

		Color& multiply(const Color& c) {
			r *= c.r;
			g *= c.g;
			b *= c.b;
			return *this;
		}

		Color& operator*=(const Color& c) {
			return multiply(c);
		}

		Color operator*(const Color& c) const {
			return Color(*this).multiply(c);
		}

		Color& multiply(float s) {
			r *= s;
			g *= s;
			b *= s;
			return *this;
		}

		Color& operator*=(float s) {
			return multiply(s);
		}

		Color operator*(float s) const {
			return Color(*this).multiply(s);
		}

		bool equals(const Color& c) const {
			return r == c.r && g == c.g && b == c.b;
		}

		bool operator==(const Color& c) const {
			return equals(c);
		}

		std::vector<float>& toArray(std::vector<float>& array, unsigned offset = 0) const {
			array.reserve(offset + 2);
			array[offset] = r;
			array[offset + 1] = g;
			array[offset + 2] = b;

			return array;
		}

		Color& fromArray(const std::array<float, 3>& array) {

			r = array[0];
			g = array[1];
			b = array[2];

			return *this;

		}

	};

}
