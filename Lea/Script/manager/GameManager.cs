using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    //���� �޴���
    public static GameManager Instance;
    //������
    public int nowfloor;
    //�� ��ȣ
    public int RoomNumber;
    #region �� ����
    //������� ��ȯ�� ���� ��
    public int EnemySpawnIndex;
    //��ȯ�Ǵ� ���� ������
    public int EndEnemySpawnIndex;
    //���� �ڽ��� �ִ� ��
    public int floor;
    #endregion
    //��Ż�� �����Ǿ����� Ȯ�� �ϴ� �Լ�
    public bool spawnpotal;
    //�����ִ� ���� �����ִ��� üũ
    public int LiveEnemyCheck;

    public GameObject ManaBoss;
    public GameObject BossUI;
    public GameObject PotalPf;

    public List<GameObject> GameMap = new List<GameObject>();


    void Start(){
        //�̱���
        if(Instance == null)
            Instance = this;
        else
            Destroy(Instance);

        RoomNumber = (int)gamedata.map.mainMap;
        PotalPf.gameObject.SetActive(false);
        spawnpotal = false;
        EnemySpawnchack();
    }

    void Update(){
        EnemyNumSet();
        BossSpwan();
        potalopen();
        boosui();

    }
    
    //�� ��ȯ
    void sceneChange(string scenename){
        SceneManager.LoadScene(scenename);
    
    }
    //������ ������
    void EnemySpawnchack()
    {
        EndEnemySpawnIndex = 40 + (5 * nowfloor);
        gamedata.littelEnemyHpData = 1 + (nowfloor * 2);
    }
    //���ӿ��� �� ��ȯ
    public void gameover()
    {
        sceneChange("GameOver");
    }
    //���� ������ ���� ��Ż�� ���� �ڵ�
    void potalopen()
    {
        LiveEnemyCheck = GameObject.FindGameObjectsWithTag("enemy").Length;
        if (spawnpotal == false && EnemySpawnIndex >= EndEnemySpawnIndex && RoomNumber == (int)gamedata.map.battelMap && LiveEnemyCheck <= 0)
        {
            spawnpotal = true;
            PotalPf.gameObject.SetActive(true);
        }
        if (RoomNumber != (int)gamedata.map.battelMap)
        {
            spawnpotal = false;
            PotalPf.gameObject.SetActive(false);
        }

        
    }
    void boosui()
    {
        if(BossUI.activeSelf == false)
        {
            if (RoomNumber == (int)gamedata.map.bossMap)
            {
                BossUI.gameObject.SetActive(true);
            }
        }
        else
        {
            if(RoomNumber != (int)gamedata.map.bossMap)
            {
                BossUI.gameObject.SetActive(false);
            }
        }
    }

    void BossSpwan()
    {
        if (GameManager.Instance.RoomNumber == (int)gamedata.map.bossMap && ManaBoss.activeSelf == false)
        {
            ManaBoss.SetActive(true);
        }
    }

    void EnemyNumSet()
    {
        if (GameManager.Instance.RoomNumber != (int)gamedata.map.battelMap)
        {
            EnemySpawnIndex = 0;
        }
        if(GameManager.Instance.RoomNumber == (int)gamedata.map.battelMap && PotalPf.activeSelf == false)
        {
            EnemySpawnchack();
        }
    }

    
}
