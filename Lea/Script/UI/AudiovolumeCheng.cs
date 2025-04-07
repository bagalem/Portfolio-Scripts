using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AudiovolumeCheng : MonoBehaviour
{
    //셋팅에 실린더에 들어가 있는 볼륨 변경 스크립트
    public Slider slider;

    public bool isEffect;

    void Start()
    {
        if (slider != null && !isEffect)
        {
            slider.onValueChanged.AddListener(OnSliderMusicValueChanged);
        }
        else if(slider != null && isEffect)
        {
            slider.onValueChanged.AddListener(OnSliderEffectValueChanged);
        }
    }

    void OnSliderMusicValueChanged(float value)
    {
        SoundManager.Instance.SetMusicVolume(value);
    }

    void OnSliderEffectValueChanged(float value)
    {
        SoundManager.Instance.SetEffectsVolume(value);
    }
}
