#ifndef INTERPOLATE_HPP
#define INTERPOLATE_HPP

/////////////////////////////////
//c++ port of Penner easing
//equations specifically with
//SFML in mind
//
//t: start time
//b: starting value being interpolated
//c: change in value
//d: duration
/////////////////////////////////

#include <math.h>
#include <algorithm>

#define PI 3.14

class interpolate
{
    public:
        interpolate();
        virtual ~interpolate();

        static float linear(float t, float b, float c, float d);
        static float expoEaseIn(float t, float b, float c, float d);
        static float expoEaseOut(float t, float b, float c, float d);
        static float expoEaseInOut(float t, float b, float c, float d);
        static float cubicEaseIn(float t, float b, float c, float d);
        static float cubicEaseOut(float t, float b, float c, float d);
        static float cubicEaseInOut(float t, float b, float c, float d);
        static float quarticEaseIn(float t, float b, float c, float d);
        static float quarticEaseOut(float t, float b, float c, float d);
        static float quarticEaseInOut(float t, float b, float c, float d);
        static float quinticEaseIn(float t, float b, float c, float d);
        static float quinticEaseOut(float t, float b, float c, float d);
        static float quinticEaseInOut(float t, float b, float c, float d);
        static float quadraticEaseIn(float t, float b, float c, float d);
        static float quadraticEaseOut(float t, float b, float c, float d);
        static float quadraticEaseInOut(float t, float b, float c, float d);
        static float sineEaseIn(float t, float b, float c, float d);
        static float sineEaseOut(float t, float b, float c, float d);
        static float sineEaseInOut(float t, float b, float c, float d);
        static float circularEaseIn(float t, float b, float c, float d);
        static float circularEaseOut(float t, float b, float c, float d);
        static float circularEaseInOut(float t, float b, float c, float d);
        static float backEaseIn(float t, float b, float c, float d);
        static float backEaseOut(float t, float b, float c, float d);
        static float backEaseInOut(float t, float b, float c, float d);
        static float elasticEaseIn(float t, float b, float c, float d);
        static float elasticEaseOut(float t, float b, float c, float d);
        static float elasticEaseInOut(float t, float b, float c, float d);
        static float bounceEaseIn(float t, float b, float c, float d);
        static float bounceEaseOut(float t, float b, float c, float d);
        static float bounceEaseHelper(float t, float b, float c, float d);
        static float bounceEaseInOut(float t, float b, float c, float d);

    public:
};

#endif // INTERPOLATE_HPP
