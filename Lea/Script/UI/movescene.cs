using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class movescene : MonoBehaviour
{
    public string SceneName;
    public void onClick(){
        SoundManager.Instance.StopMusic();
        StartCoroutine(fadeinoutmanager.Instance.FadeIn(SceneName));
    }
    public void NextScene()
    {
        SceneManager.LoadScene(SceneName);
    }

    public void quit()
    {
        Application.Quit();
    }
}
