using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public GameObject menuSet;
    private static GameManager instance;

    public static GameManager Instance { get { return instance; } }

    public bool isGameover = false;
    public GameObject gameoverUI;
    public Text scoreText;
    public Button TitleBtn;
    public string sceneName;


    private int score = 0;

    void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        else
        {
            Debug.LogWarning("���� �ΰ� �̻��� ���� �Ŵ����� �����մϴ�!");
            Destroy(gameObject);
        }

    }

    void Start()
    {
        // �ʱ� ���� ����
        scoreText.text = "Score: " + score;

        TitleBtn.onClick.AddListener(OnClickTitleBtn); 
        
    }

    void Update()
    {
        // ���� ���� ���¿��� ������ ������� �� �ְ� �ϴ� ó��
        if (isGameover && Input.GetMouseButtonDown(0))
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }

        // esc�� �޴� ���� �ѱ�
        if (Input.GetButtonDown("Cancel"))
        {
            menuSet.SetActive(!menuSet.activeSelf);
        }
    }

    public void OnClickTitleBtn()
    {
        // ������ ��ȯ
        SceneManager.LoadScene(sceneName);
    }

    // ������ ������Ű�� �޼���
    public void AddScore(int newScore)
    {
        if (!isGameover) // ���� ���� ���°� �ƴ� ��쿡�� ���� ����
        {
            score += newScore;
            scoreText.text = "Score: " + score;
        }
    }

    // �÷��̾� ĳ���Ͱ� ����� ���� ������ �����ϴ� �޼���
    public void OnPlayerDead()
    {
        isGameover = true;
        gameoverUI.SetActive(true);
    }

    public void GameExit() // ���� ����
    {
        Application.Quit();
    }
}
