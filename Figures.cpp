#include <SFML/Graphics.hpp>
#include "Figures.h"
#include <cmath>

using namespace gm;

RoundRect::RoundRect(sf::Vector2f size, float radius)
	: m_size(size)
	, m_radius(radius) {
	update();
}

void RoundRect::setSize(sf::Vector2f size) {
	m_size = size;
	update();
}

sf::Vector2f RoundRect::getSize() const {
	return m_size;
}

void RoundRect::setRadius(float radius) {
	m_radius = radius;
	update();
}

float RoundRect::getRadius() const {
	return m_radius;
}

namespace {
	static constexpr std::size_t corner_points = 16;
	static constexpr float pi = 3.141592654;
} // namespace

std::size_t RoundRect::getPointCount() const {
	return corner_points * 4;
}

sf::Vector2f RoundRect::getPoint(std::size_t index) const {
	float da = 90.f / (corner_points - 1);
	auto centre_i = index / corner_points;

	sf::Vector2f centre{ centre_i == 1 || centre_i == 2 ? m_radius : m_size.x - m_radius,
						centre_i == 0 || centre_i == 1 ? m_radius : m_size.y - m_radius };

	return { m_radius * std::cos(da * (index - centre_i) * pi / 180) + centre.x,
		   -m_radius * std::sin(da * (index - centre_i) * pi / 180) + centre.y };
}

Squircle::Squircle(float radius, float n, std::size_t resolution)
	: m_radius(radius)
	, m_n(n)
	, m_resolution(resolution) {
	update();
}

void Squircle::setRadius(float radius) {
	m_radius = radius;
	update();
}

float Squircle::getRadius() const {
	return m_radius;
}

void Squircle::setN(float p) {
	m_n = p;
	update();
}

float Squircle::getN() const {
	return m_n;
}

void Squircle::setResolution(std::size_t resolution) {
	m_resolution = resolution;
	update();
}

std::size_t Squircle::getResolution() const {
	return m_resolution * 4;
}

namespace {

	static constexpr float map(float value, float a, float b, float c, float d) {
		return (value - a) / (b - a) * (d - c) + c;
	}

	static constexpr float sign(float value) {
		if (value > 0) return 1;
		if (value < 0) return -1;
		return 0;
	}
} // namespace

std::size_t Squircle::getPointCount() const {
	return m_resolution * 4;
}

sf::Vector2f Squircle::getPoint(std::size_t index) const {
	auto local = index % (m_resolution * 2);
	// to go clockwise around the whole shape, flip the bottom half
	auto bottom = (index >= m_resolution * 2) ? -1.f : 1.f;

	auto x = map(local, 0, m_resolution * 2, -1, 1);
	// cubic easing function: dedicate more vertices to the corners
	x = (1 - std::pow(1 - std::abs(x), 3)) * sign(x) * bottom;
	x = map(x, -1, 1, -m_radius, m_radius);

	auto y = m_radius * std::pow(1.f - std::pow(std::abs(x / m_radius), m_n), 1.f / m_n);

	return { x, y * bottom };
}


