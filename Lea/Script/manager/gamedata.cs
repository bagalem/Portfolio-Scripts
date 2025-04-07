using System.Collections.Generic;
using System.Resources;
using UnityEditor;
using UnityEngine;

namespace data
{
    public class gamedata : GameManager
    {
        //자주 사용하거나 참조 많이 할것같은 변수 모음

        #region 게임 메니저
        public static bool ActionData = false;
        //SpawnManager 에서 스폰을 활성화 시킬지 비활성화 시킬지 정하는 변수
        public static bool Active;
        #endregion

        #region 책
        public static List<int> MagicBookData = new List<int>();
        public static float bookspeedData = 5;
        #endregion

        #region 맵
        public enum map
        {
            mainMap = 1,
            battelMap = 2,
            shelterMap = 3,
            bossMap = 4
        }
        #endregion

        #region 체크
        public static bool canbookpoenData = true;
        public static bool holdfireData = true;
        public static bool ChangSetUiColorData = true;
        public static float HoldTimeData = 0;
        public static float HoldEndTimeData = 3;
        public static int MagicMumData = 0;
        #endregion

        #region stats
        public static int Stats0BuyCoin = 50;
        public static int Stats1BuyCoin = 50;
        public static int Stats2BuyCoin = 50;
        public static int stats0LV = 1;
        public static int stats1LV = 1;
        public static int stats2LV = 1;
        #endregion

        #region 플레이어
        public static int PlayerHpMaxBaseData = 10;
        public static int PlayerSpeedData = 5;
        public static int PlayerDamagData = 2;
        public static int coin;
        public static float MagicShootDelayData = 0.7f;
        //기본적으로 올릴수 있는 스텟이 존재하며 방어력 또한 존재한다. 방어력의 식은 체력의 + 된 값과 비슷하다.
        #endregion
        
        #region 적
        public static int littelEnemyHpData = 2;
        public static int MiddleEnemyHpData = 6;
        public static int bossEnemyHpData = 800;
        public static int enemydamage = 1;
        public static int EnemyspeedData = 2;
        public static float EnemySpwanDelayData = 3;
        public static float EnemyShootDelay = 3;
        public static bool ChackElectroData = false;
        // 적에 따른 데미지 차이 : 맵 을 점점 올라갈수록 몬스터의 데미지가 0.2씩 늘어남 이건 HP에도 적용됨 발사 하는 적의 경우 에도 데미지는 올라감
        #endregion
        
        #region 마법
        public static float ManaSpeedData = 25f;
        public static int FireBulletNumData = 4;
        public static int manaMagicDamege = 2;
        public static int fireMagicDamege = 1;
        public static int electroMagicDamege = 1;
        // 데미지 계산식 : (데미지) + (속성 마법 데미지(불,마나,전기 ,빛)) -+ (약점 유무의 따른 데미지(약점이면 X2 관계없으면 X1 약점에 반하면 X 0.5))
        #endregion
    }
}

