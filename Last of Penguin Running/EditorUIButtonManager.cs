using Lop.Editor;
using LopRunning.ObjectTile;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;

public class EditorUIButtonManager : MonoBehaviour
{
    private static EditorUIButtonManager instence;
    public static EditorUIButtonManager Instence { get { return instence; } }

    public MapEditor Editor;

    //오브젝트 슬롯 오브젝트
    public GameObject SlotObject;
    #region SlotObject
    [Header("슬롯들")]
    // Tile 창
    public GameObject TileSlot;
    // Monster 창
    public GameObject MonsterSlot;
    //Object 창
    public GameObject ObjectSlot;
    //Jelly 창
    public GameObject JellySlot;
    #endregion
    #region Scroll
    [Header("스크롤")]
    //Tile 스크롤
    public GameObject TileSlotScroll;
    //Object 스크롤
    public GameObject ObjectSlotScroll;
    //Monster 스크롤
    public GameObject MonsterSlotScroll;
    //Jelly 스크롤
    public GameObject JellySlotScroll;
    #endregion
    #region Button
    [Header("버튼")]
    //타일 버튼
    public GameObject TileButton;
    //오브젝트 버튼
    public GameObject ObjectButton;
    //몬스터 버튼
    public GameObject MonsterButton;
    //젤리 버튼
    public GameObject JellyButton;
    //테스트 시작 버튼
    public GameObject StartButton;
    //되돌리기 버튼
    public GameObject UndoButton;
    //되돌리기 취소 버튼
    public GameObject RedoButton;
    //저장 버튼
    public GameObject SaveButton;
    //Editor 나가기 버튼
    public GameObject BackButton;
    //오브젝트 슬롯비활성화 버튼
    public GameObject ObjectSlotActive_button;
    //슬록 오른쪽 버튼
    public GameObject SlotRightButton;
    //슬롯 왼쪽 버튼
    public GameObject SlotLeftButton;
    #endregion
    #region Mode Button
    //Move 모드 변경 버튼
    public GameObject MapSizeChangeIconButton;
    // Zoom In 버튼
    public GameObject ZoomInIconButton;
    // Zoom Out 버튼
    public GameObject ZoomOutIconButton;
    //PrintMode 선택 버튼
    public GameObject PaintModeIconButton;
    //Eraser 버튼
    public GameObject EraserIconButton;
    //Select 모드 선택 버튼
    public GameObject SelectModeIconButton;

    #endregion
    [Header("그 외")]
    public GameObject ToolBar;
    public GameObject UpDownButton;

    public Sprite Down;
    public Sprite Up;

    float AddcameraSize = 0.1f;

    RectTransform ToolPosition;

    [Header("리스트업")]
    [SerializeField]
    private List<GameObject> TileList;
    [SerializeField]
    private List<GameObject> ObjectList;
    [SerializeField]
    private List<GameObject> JellyList;
    [SerializeField]
    private List<GameObject> MonsterList;

    void Awake()
    {
        if (instence == null)
            instence = this;
        else
            Destroy(this);
    }

    void Start()
    {
        

        #region UI버튼에 기능 할당
        StartButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { Editor.Preview(); });
        UndoButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { Editor.Buffer.Undo(); });
        RedoButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { Editor.Buffer.Redo(); });
        SaveButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { Editor.MapSave(); });
        BackButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { Editor.SceneBack(); });
        SlotRightButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { MoveSlot(1, SlotActvie(), ReturnItemIndex(), ReturnActvieList()); });
        SlotLeftButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { MoveSlot(-1, SlotActvie(), ReturnItemIndex(), ReturnActvieList()); });
        ObjectSlotActive_button.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { SlotOnOff(SlotObject); });
        TileButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { if (SlotObject.activeSelf == false) { SlotOnOff(SlotObject); } OnSelectSlot(TileSlot); });
        ObjectButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { if (SlotObject.activeSelf == false) { SlotOnOff(SlotObject); } OnSelectSlot(ObjectSlot); });
        JellyButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { if (SlotObject.activeSelf == false) { SlotOnOff(SlotObject); } OnSelectSlot(JellySlot); });
        MonsterButton.GetComponent<UnityEngine.UI.Button>().onClick.AddListener(() => { if (SlotObject.activeSelf == false) { SlotOnOff(SlotObject); } OnSelectSlot(MonsterSlot); });
        #endregion
        #region ModeUI 버튼에 기능 할당 
        MapSizeChangeIconButton.GetComponent<Button>().onClick.AddListener(() => { MapSizeChange(); });
        SelectModeIconButton.GetComponent<Button>().onClick.AddListener(() => { ChangeMode(0); });
        PaintModeIconButton.GetComponent<Button>().onClick.AddListener(() => { ChangeMode(1); });
        UpDownButton.GetComponent<Button>().onClick.AddListener(() => { ToolOpenClose(); });
        EraserIconButton.GetComponent<Button>().onClick.AddListener(() => { TileRemove(); });
        ZoomInIconButton.GetComponent<Button>().onClick.AddListener(() => { ZoomIn(); });
        ZoomOutIconButton.GetComponent<Button>().onClick.AddListener(() => { ZoomOut(); });
        #endregion

        ToolPosition = UpDownButton.GetComponent<RectTransform>();
    }

    void SlotOnOff(GameObject obj)
    {
        //오브젝트를 끄고 킬수 있는 함수
        if (obj.activeSelf)
        {
            obj.SetActive(false);
        }
        else
        {
            obj.SetActive(true);
        }
    }

    void OnSelectSlot(GameObject SelectSlot)
    {
        //selectSlot 으로 받은 오브젝트외에 전부 비활성화 시키는 모드
        GameObject[] list = { TileSlot, ObjectSlot, JellySlot, MonsterSlot };
        for (int i = 0; i < list.Length; i++)
        {
            if (list[i] == SelectSlot)
            {
                list[i].SetActive(true);
            }
            else
            {
                list[i].SetActive(false);
            }
        }
    }

    GameObject SlotActvie()
    {
        //현제 어떤 슬롯이 켜저 있는지 체크하는 함수
        GameObject ReturnObject = null;

        GameObject[] list = { TileSlot, JellySlot, ObjectSlot, MonsterSlot };
        GameObject[] ScrollList = { TileSlotScroll, JellySlotScroll, ObjectSlotScroll, MonsterSlotScroll };

        for (int i = 0; i < list.Length; i++)
        {
            if (list[i].activeSelf == true)
            {
                ReturnObject = ScrollList[i].gameObject;
                break;
            }
        }

        return ReturnObject;

    }

    int ReturnItemIndex()
    {
        //MoveSlot에 들어가는 한 슬롯에 들어가는 타일의 수를 구해서 반환하는 함수
        //크기상 타일은 한 슬롯창에 12개 몬스터는 한 창에 6개씩 들어갈수 있다
        if (SlotActvie() == TileSlotScroll || SlotActvie() == JellySlotScroll || SlotActvie() == ObjectSlotScroll)
        {
            return 12;
        }
        else if (SlotActvie() == MonsterSlotScroll)
        {
            return 6;
        }
        return 0;
    }

    List<GameObject> ReturnActvieList()
    {
        //켜저있는 슬롯의 리스트를 반환하는 함수
        if (SlotActvie() == TileSlotScroll)
        {
            return TileList;
        }
        else if (SlotActvie() == ObjectSlotScroll)
        {
            return ObjectList;
        }
        else if (SlotActvie() == JellySlotScroll)
        {
            return JellyList;
        }
        else if (SlotActvie() == MonsterSlotScroll)
        {
            return MonsterList;
        }

        return null;
    }
    //슬롯의 타일 화면번호
    int Slotindex = 0;

    public void MoveSlot(int direction, GameObject SlotScroll, int PageItemIndex, List<GameObject> TileList)
    {
        //슬롯을 움직이는 함수

        //슬롯에 화살표를 눌렀을때 다음으로 넘기는 함수
        int SlotMaxIndex = 0;

        for (int i = 1; i < TileList.Count; i++)
        {
            if (i % 12 == 0)
            {
                SlotMaxIndex++;
            }
        }

        if (SlotMaxIndex != 0)
        {
            //방향을 검사 (-1이면 왼쪽 1 이면 오른쪽)
            if (direction > 0)
            {
                Slotindex++;
            }
            else if (direction < 0)
            {
                Slotindex--;
            }

            //최댓값 최솟값 안넘어가게 예외처리
            if (Slotindex > SlotMaxIndex)
            {
                Slotindex = 0;
            }
            else if (Slotindex < 0)
            {
                Slotindex = SlotMaxIndex;
            }

            //(보여주고 싶은칸 * 아이템크기) / (전체영역 - 보여주는 영역) 

            float value = 0;

            value = (Slotindex * SlotScroll.gameObject.GetComponent<RectTransform>().rect.width) /
                    (SlotScroll.gameObject.GetComponent<ScrollRect>().content.rect.width - SlotScroll.gameObject.GetComponent<RectTransform>().rect.width);

            SlotScroll.GetComponent<ScrollRect>().horizontalNormalizedPosition = ((int)value);
        }
    }

    

    void ToolOpenClose()
    {
        //툴을 열고 닫는 함수
        if (ToolBar.activeSelf)
        {
            ToolBar.SetActive(false);
            ToolPosition.anchoredPosition = new Vector3(ToolPosition.anchoredPosition.x, ToolPosition.anchoredPosition.y + 91, 1);
            UpDownButton.GetComponent<Image>().sprite = Down;
        }
        else
        {
            ToolBar.SetActive(true);
            ToolPosition.anchoredPosition = new Vector3(ToolPosition.anchoredPosition.x, ToolPosition.anchoredPosition.y - 91, 1);
            UpDownButton.GetComponent<Image>().sprite = Up;
        }
    }

    void TileRemove()
    {
        //지우개 UI를 눌렀을때 실행되는 함수
        ChangeMode(1);
        Editor.CurrentTileElement = ObjectType.None;
        Editor.CurrentJellyElement = JellyType.None;
    }

    void ZoomIn()
    {
        AddcameraSize += 0.1f;
        Editor.SetSize(AddcameraSize);
    }

    void ZoomOut()
    {
        AddcameraSize += -0.1f;
        Editor.SetSize(AddcameraSize);
    }

    void MapSizeChange()
    {
        //맵사이즈 변경 버튼을 눌렀을때 실행되는 함수
        Editor.OpenResizePopup();
    }
    public void ModeChange(int index, bool jellyChack)
    {
        //모드를 바꾸는 모드
        if (jellyChack)
        {
            Editor.CurrentJellyElement = (JellyType)index;
            ChangeMode(2);
        }
        else
        {
            Editor.CurrentTileElement = (ObjectType)index;
            ChangeMode(1);
        }
    }

    public void ChangeMode(int number)
    {
        Editor.SetMode(number);
    }

    public List<GameObject> GetTileList()
    {
        return TileList;
    }
    public List<GameObject> GetObjectList()
    {
        return ObjectList;
    }
    public List<GameObject> GetJellyList()
    {
        return JellyList;
    }
    public List<GameObject> GetMonsterList()
    {
        return MonsterList;
    }

    void TestingGameStart()
    {

    }
}



