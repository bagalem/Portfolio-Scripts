using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class DelayMoveScene : MonoBehaviour
{
    public float DelayTime;
    public string Scenename;
    void Start()
    {
        StartCoroutine(NextScene());
        StartCoroutine(playSound());
    }
    IEnumerator NextScene()
    {
        yield return new WaitForSeconds(DelayTime);
        SceneManager.LoadScene(Scenename);
    }
    IEnumerator playSound()
    {
        yield return new WaitForSeconds(0.1f); 
        SoundManager.Instance.PlayEffect(0);
    }
}
