using UnityEngine;
using System.Collections.Generic;
using System.IO;
using UnityEngine.Audio;
using UnityEngine.SceneManagement;
using data;
using Unity.VisualScripting;
//using UnityEditor.SearchService;

public class SoundManager : MonoBehaviour
{
    public static SoundManager Instance;

    public AudioSource musicSource;
    public AudioSource effectsSource;

    public AudioMixer soundaudioMixer;
    public AudioMixer effectaudioMixer;

    public List<AudioClip> audioClips;
    public List<AudioClip> effectClips;

    Scene scene;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
        }
        else
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }

    }

    void Update()
    {
        StartAudio();    
    }

    public void StartAudio()
    {
        scene = SceneManager.GetActiveScene();
        if (scene.name == "Title")
        {
            if (musicSource.clip != audioClips[0])
            {
                PlayMusic(0);
            }
        }
        else if (scene.name == "GameOver")
        {
            PlayMusic(1);
        }
        
        if (scene.name == "InGame" && GameManager.Instance.RoomNumber == (int)gamedata.map.shelterMap)
        {
            PlayMusic(2);
        }
        if (scene.name == "InGame" && GameManager.Instance.RoomNumber == (int)gamedata.map.battelMap)
        {
            PlayMusic(3);
        }

        if (scene.name == "InGame" && GameManager.Instance.RoomNumber == (int)gamedata.map.bossMap)
        {
            PlayMusic(4);
            effectsSource.loop = true;
            PlayEffect(1);
        }

        if (scene.name == "Credit")
        {
            PlayMusic(5);
        }

        if (scene.name == "Splash")
        {
            effectsSource.loop = false;
            StopMusic();
        }

        
    }

    public void PlayMusic(int number)
    {
        if (audioClips[number] != null)
        {
            if(musicSource.clip != audioClips[number])
            {
                musicSource.clip = audioClips[number];
                musicSource.Play();
            }
        }
    }
    

    public void PlayEffect(int number)
    {
        if (effectClips[number] != null)
        {
            if (effectsSource.clip != effectClips[number])
            {
                effectsSource.clip = effectClips[number];
                effectsSource.Play();
            }
                
        }
    }

    public void PlayEffectSound(int number)
    {
        if (effectClips[number] != null)
        {
            effectsSource.PlayOneShot(effectClips[number]);
        }
    } 

    public void StopMusic()
    {
        musicSource.Stop();
    }

    public void StopEffect()
    {
        effectsSource.Stop();
    }

    public void SetMusicVolume(float volume)
    {
        musicSource.volume = volume;
    }

    public void SetEffectsVolume(float volume)
    {
        effectsSource.volume = volume;
    }
}