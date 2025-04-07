using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using static UnityEngine.Rendering.DebugUI;

public class SoundManager : MonoBehaviour
{
    private static SoundManager instance;
    public static SoundManager Instance { get { return instance; } }

    public AudioSource EffectSource;
    public AudioSource SoundSource;

    public Slider BackGroundSoundSlider;
    public Slider EffectSoundSlider;

    public List<AudioClip> SoundClipList;
    public List<AudioClip> EffectClipList;

    // Start is called before the first frame update
    void Start()
    {
        if (instance == null)
            instance = this;
        else
            Destroy(Instance);


        if (BackGroundSoundSlider != null)
        {
            BackGroundSoundSlider.onValueChanged.AddListener(SetVolumSound);
            BackGroundSoundSlider.value = 1;
        }
        if (EffectSoundSlider != null)
        {
            EffectSoundSlider.onValueChanged.AddListener(SetVolumEffect);
            EffectSoundSlider.value = 1;
        }
            
    }

    public void PlaySound(int Index)
    {
        if (SoundClipList != null)
        {
            SoundSource.clip = SoundClipList[Index];
            SoundSource.Play();
        }
    }
    public void PlayEffect(int Index)
    {
        if (EffectClipList != null)
        {
            EffectSource.clip = EffectClipList[Index];
            EffectSource.Play();
        }
    }

    public void SetVolumSound(float value)
    {
        SoundSource.volume = value;
    }

    public void SetVolumEffect(float value)
    {
        EffectSource.volume = value;
    }
}
