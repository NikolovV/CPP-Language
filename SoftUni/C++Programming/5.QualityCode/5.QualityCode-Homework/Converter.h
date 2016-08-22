#ifndef CONVERTER_H
#define CONVERTER_H

namespace GraphicsFramework
{
// Convert metric unit.
class Conveter
{
public:
    float convert_kmH_in_ms(float kmInHour)
    {
        float meterInSecon = kmInHour * 1000 / 3600;
        return meterInSecon;
    }
};
}

#endif /* CONVERTER_H */