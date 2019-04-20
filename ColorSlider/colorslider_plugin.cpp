#include "colorslider_plugin.h"
#include "colordefiner.h"
#include <qqml.h>

void ColorSliderPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    Q_ASSERT(uri == QLatin1String("ColorSlider"));
    qmlRegisterType<ColorDefiner>(uri, 1, 0, "ColorDefiner");
}

