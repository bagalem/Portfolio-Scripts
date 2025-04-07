using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class fadeinoutmanager : MonoBehaviour
{
    private static fadeinoutmanager instance;
    public static fadeinoutmanager Instance { get { return instance; } }

    public GameObject FadeBackground;

    Image image;

    Color currentColor;

    private void Start()
    {
        image = FadeBackground.GetComponent<Image>();

        if (instance == null)
        {
            instance = this;
        }
        else
        {
            Destroy(instance);
        }
    }

    public IEnumerator FadeIn(string SceneName)
    {
        currentColor = image.color;

        currentColor.a = 0;
        image.color = currentColor;

        for (float i = 0; i < 100; i++)
        {
            yield return null;
            currentColor = image.color;
            currentColor.a = i / 100f;
            image.color = currentColor;
        }

        SceneManager.LoadScene(SceneName);

    }

    public IEnumerator FadeOut()
    {
        yield return new WaitForSeconds(2f);
        for (float i = 100; i > 0; i--)
        {
            yield return null;
            currentColor = image.color;
            currentColor.a = i / 100f;
            image.color = currentColor;
        }
    }
}
