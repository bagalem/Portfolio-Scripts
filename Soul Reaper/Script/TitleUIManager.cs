using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class TitleUIManager : MonoBehaviour
{
    public Button StartBtn;
    public Button SettingBtn; // ���� ��ư �߰�
    public Button SettingEsc; //����â ������ ��ư
    public Button HelpBtn; //���� ��ư �߰�
    public Button HelpEsc; //���� ������ ��ư

    public string sceneName;
    public Image settingpage;
    public Image helppage;

    // Start is called before the first frame update
    void Start()
    {
        StartBtn.onClick.AddListener(OnClickStartBtn);
        SettingBtn.onClick.AddListener(OnClickSettingBtn);
        SettingEsc.onClick.AddListener(OnClickSettingEsc);
        HelpBtn.onClick.AddListener(OnClickHelpBtn);
        HelpEsc.onClick.AddListener(OnClickHelpEsc);


        // ó���� �̹����� ��Ȱ��ȭ
        settingpage.gameObject.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {

    }

    void OnClickStartBtn() // ���� ����
    {
        // ������ ��ȯ
        SceneManager.LoadScene(sceneName);
    }

    void OnClickSettingBtn() // ���� ��ư Ŭ�� ��
    {
        // �̹����� Ȱ��ȭ
        settingpage.gameObject.SetActive(true);
    }
    void OnClickHelpBtn() // ���� ��ư Ŭ�� ��
    {
        // �̹����� Ȱ��ȭ
        helppage.gameObject.SetActive(true);
    }

    void OnClickSettingEsc()
    {
        settingpage.gameObject.SetActive(false);
    }
    void OnClickHelpEsc()
    {
        helppage.gameObject.SetActive(false);
    }

    void OnClickHelp()
    {
        helppage.gameObject.SetActive(true);
    }
    public void GameExit()
    {
        Application.Quit();
    }
}
