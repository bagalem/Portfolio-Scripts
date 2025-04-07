using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameOverUIManager : MonoBehaviour
{
    public CanvasGroup Text;
    public CanvasGroup Butten;

    // Start is called before the first frame update
    void Start()
    {
        Text.alpha = 0;
        Butten.alpha = 0;
        StartCoroutine(GameOverAnimetion());
    }
    
    IEnumerator GameOverAnimetion()
    {
        for (int i = 0; i< 100; i++)
        {
            Text.alpha = i / 100f;
            if (Input.GetMouseButtonDown(0))
            {
                Text.alpha = 1.0f;
                break;
            }
            yield return new WaitForSeconds(0.05f);
            
        }
        
        yield return new WaitForSeconds(1f);

        for (int i = 0; i< 100; i++)
        {
            Butten.alpha = i / 100f;
            if (Input.GetMouseButtonDown(0))
            {
                Butten.alpha = 1.0f;
                break;
            }
            yield return new WaitForSeconds(0.05f);
        }
    }
}
