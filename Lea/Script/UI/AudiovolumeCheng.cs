using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class AudiovolumeCheng : MonoBehaviour
{
    //���ÿ� �Ǹ����� �� �ִ� ���� ���� ��ũ��Ʈ
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
