import QtQuick 2.3
Item{
    id: root

    // Value between 0 (0%) and 1 (100%)
    property real value: batteryClass.currentVolt
    // Battery is being charged
    property bool charging: batteryClass.charging

    property real __smoothedValue: batteryClass.currentVolt
    // True when battery is running low
    property bool __batteryLow: batteryClass.lowCharge

    x: 400
    width: 200
    height: 35

    Timer{
        id: blinkBattery
        interval: 300
        running: (__batteryLow && !charging)
        repeat: true
        onTriggered:
        {
            root.visible  = !root.visible
        }
        onRunningChanged: {
            root.visible = true;
        }
    }

//    Image{
//        id: chargerNotify
//        anchors.right: root.left
//        anchors.rightMargin: 0
//        source: "image/Battery/plug.png"
//        visible: charging
//    }

    Image {
        id: batteryBar
        anchors.fill: parent
        source: "qrc:/images/battery/battery_bar.png"
        visible: false
    }


    Behavior on __smoothedValue {
        SmoothedAnimation {
            velocity: 0.1
            duration: 1200
        }
    }

    ShaderEffectSource {
        id: particlesShaderSource
        anchors.fill: batteryBar//particlesItem
        sourceItem: batteryBar  //particlesItem
        hideSource: true
        visible: false
    }

    ShaderEffect {
        id: shaderEffectItem
        anchors.fill: particlesShaderSource

        property variant source: batteryBar
        property variant source2: particlesShaderSource
        property real value: 0.10 + root.__smoothedValue*0.80 // нужно для правильной пропорции для шейдера.
                                                              // отступы на рисунке батареи это края плюс и минус батареи

        fragmentShader: "
            uniform sampler2D source;
            uniform sampler2D source2;
            uniform lowp float qt_Opacity;
            varying highp vec2 qt_TexCoord0;
            uniform highp float value;
            uniform highp float rot;
            void main() {
                lowp vec4 pix = texture2D(source, qt_TexCoord0);
                lowp vec4 pix2 = texture2D(source2, qt_TexCoord0);
                highp float r = qt_TexCoord0.y*(rot*0.008) - 0.0042*rot + abs(rot)*(value-0.5)*0.006;
                highp float isVis = smoothstep(qt_TexCoord0.x-0.02-r, qt_TexCoord0.x+0.02-r, value);
                highp vec4 color = vec4(1.0 - value, value, 0.0, 1.0);
                highp vec4 light =  color * isVis * pix;
                gl_FragColor = (light) * qt_Opacity;
            }"
    }

    /*
        fragmentShader: "
            uniform sampler2D source;
            uniform sampler2D source2;
            uniform lowp float qt_Opacity;
            varying highp vec2 qt_TexCoord0;
            uniform highp float value;
            uniform highp float rot;
            void main() {
                lowp vec4 pix = texture2D(source, qt_TexCoord0);
                lowp vec4 pix2 = texture2D(source2, qt_TexCoord0);
                highp float r = qt_TexCoord0.y*(rot*0.008) - 0.0042*rot + abs(rot)*(value-0.5)*0.006;
                highp float isVis = smoothstep(qt_TexCoord0.x-0.02-r, qt_TexCoord0.x+0.02-r, value);
                highp vec4 color = vec4(1.0 - value, value, 0.0, 1.0);
                highp vec4 light =  color * isVis * pix;
                gl_FragColor = (isVis * pix.a * pix2 + light) * qt_Opacity;
            }"
    */
    Image {
        anchors.fill: parent
        id: batteryImage
        source: "qrc:/images/battery/battery2.png"
    }
}
