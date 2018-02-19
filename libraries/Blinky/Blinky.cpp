#include <FastLED.h>
#include <Blinky.h>

ColorWheel::ColorWheel( int numSteps )
{
    reset();
    setSteps( numSteps );
}

void ColorWheel::reset()
{
    m_hue = 0;
}

void ColorWheel::reverse()
{
    m_step = -m_step;
}

void ColorWheel::setSteps( int numSteps )
{
    if (numSteps == 0)
	m_step = 0;
    else
	m_step = 65536L / numSteps;
}

CHSV ColorWheel::color()
{
    return CHSV( m_hue >> 8, 255, 255 );
}

CHSV ColorWheel::next()
{
    uint16_t curHue = m_hue;
    m_hue += m_step;

    return CHSV( curHue >> 8, 255, 255 );
}

