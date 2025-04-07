using System.Collections;
using System.Collections.Generic;
using data;
using UnityEngine;
using UnityEngine.Rendering;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    //게임 메니져
    public static GameManager Instance;
    //현제층
    public int nowfloor;
    //방 번호
    public int RoomNumber;
    #region 적 스폰
    //현재까지 소환된 적의 수
    public int EnemySpawnIndex;
    //소환되는 최종 마릿수
    public int EndEnemySpawnIndex;
    //현재 자신이 있는 층
    public int floor;
    #endregion
    //포탈이 생성되었는지 확인 하는 함수
    public bool spawnpotal;
    //살이있는 적이 남아있는지 체크
    public int LiveEnemyCheck;

    public GameObject ManaBoss;
    public GameObject BossUI;
    public GameObject PotalPf;

    public List<GameObject> GameMap = new List<GameObject>();


    void Start(){
        //싱글톤
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
    
    //씬 전환
    void sceneChange(string scenename){
        SceneManager.LoadScene(scenename);
    
    }
    //스폰할 마릿수
    void EnemySpawnchack()
    {
        EndEnemySpawnIndex = 40 + (5 * nowfloor);
        gamedata.littelEnemyHpData = 1 + (nowfloor * 2);
    }
    //게임오버 씬 전환
    public void gameover()
    {
        sceneChange("GameOver");
    }
    //다음 맵으로 가는 포탈을 여는 코드
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
