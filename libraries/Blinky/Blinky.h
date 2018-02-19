#pragma once

template <uint8_t PIN>
class Blinky {
private:
    int m_numLeds;
    CRGB *m_leds;

    void initialize();
    
public:
    Blinky( int numLeds );
    ~Blinky();

    CRGB* led( int n );
    int size();

    void clear();
    void fill( CRGB color );
    void shiftLeft( CRGB new_color );
    void shiftRight( CRGB new_color );
    void rotateLeft();
    void rotateRight();
};

template <uint8_t PIN>
Blinky<PIN>::Blinky( int numLeds )
    : m_numLeds(numLeds), m_leds(NULL)
{
}

template <uint8_t PIN>
Blinky<PIN>::~Blinky()
{
    delete m_leds;
}

template <uint8_t PIN>
void Blinky<PIN>::initialize()
{
    if (!m_leds) {
	m_leds = new CRGB[m_numLeds];
	FastLED.addLeds<WS2812, PIN, GRB>(m_leds, m_numLeds);
    }
}

template <uint8_t PIN>
int Blinky<PIN>::size()
{
    return m_numLeds;
}

template <uint8_t PIN>
void Blinky<PIN>::clear()
{
    fill(0);
}

template <uint8_t PIN>
void Blinky<PIN>::fill( CRGB color )
{
    initialize();

    for (int i = 0; i < m_numLeds; i++)
	m_leds[i] = color;
}

template <uint8_t PIN>
void Blinky<PIN>::shiftLeft( CRGB new_color )
{
    initialize();

    for (int i = 0; i < m_numLeds - 1; i++)
	m_leds[i] = m_leds[i + 1];

    m_leds[m_numLeds - 1] = new_color;
}

template <uint8_t PIN>
void Blinky<PIN>::shiftRight( CRGB new_color )
{
    initialize();

    for (int i = m_numLeds - 1; i > 0; i--)
	m_leds[i] = m_leds[i - 1];

    m_leds[0] = new_color;
}

template <uint8_t PIN>
void Blinky<PIN>::rotateLeft()
{
    shiftLeft( m_leds[0] );
}

template <uint8_t PIN>
void Blinky<PIN>::rotateRight()
{
    shiftRight( m_leds[m_numLeds - 1] );
}

class ColorWheel {
private:
    uint16_t m_hue;
    int16_t m_step;

public:
    ColorWheel( int numSteps );

    void reset();
    void reverse();
    void setSteps( int numSteps );

    CHSV color();
    CHSV next();
};

