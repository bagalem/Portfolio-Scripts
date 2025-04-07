using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;


public class TileUI: MonoBehaviour, IPointerDownHandler, IPointerEnterHandler, IPointerExitHandler
{
    [SerializeField] private int TileIndex;
    [SerializeField] public bool isJelly;

    //UI크기
    Transform Scale;
    //커지는 수치
    float AddSize;

    //오브젝트가 타일의 위나 아래에 설치 되어야 할때 그걸 알려주는 설명을 띄우는 스크립트
    bool Hovered;

    public GameObject Explanation;
    public GameObject Canvas;
    GameObject ExplanationObject;
    bool UseDescriptions;

    public void changeNumber(int number, bool jellyChack)
    {
        //슬롯의 타입번호를 바꾸는 함수
        TileIndex = number;
        isJelly = jellyChack;
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        //타일을 선택해서 IconManager에 넘기는 함수
        EditorUIButtonManager.Instence.ModeChange(TileIndex, isJelly);
    }

    void Start()
    {
        AddSize = 0.2f;
        Scale = GetComponent<Transform>();

        Hovered = false;
    }
    public void OnPointerEnter(PointerEventData eventData)
    {
        //마우스를 호버시 사이즈 크기 키움
        Scale.localScale = new Vector2(transform.localScale.x + AddSize, transform.localScale.y + AddSize);

        if (UseDescriptions)
        {
            Hovered = true;
            ShowExplanation();
        }
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        //마우스 호버해제시 원래의 크기로 돌아옴
        Scale.localScale = new Vector2(transform.localScale.x - AddSize, transform.localScale.y - AddSize);

        if (UseDescriptions)
        {
            Hovered = false;
            Destroy(ExplanationObject);
        }

    }

    void ShowExplanation()
    {

        if (Hovered)
        {
            var obj = Instantiate(Explanation);
            obj.transform.SetParent(Canvas.transform);


            Vector3 screenPosition = Camera.main.WorldToScreenPoint(gameObject.transform.position);

            // 스크린 좌표를 RectTransform 로컬 좌표로 변환
            RectTransformUtility.ScreenPointToLocalPointInRectangle(
                Canvas.GetComponent<Canvas>().transform as RectTransform,
                screenPosition,
                Canvas.GetComponent<Canvas>().renderMode == RenderMode.ScreenSpaceOverlay ? null : Camera.main,
                out Vector2 localPoint);
            localPoint.x = (localPoint.x / 100);
            localPoint.y = (localPoint.y / 100) - 980;
            if (localPoint.x > 1820)
            {
                localPoint.x -= 100;
            }
            Debug.Log(localPoint);
            // UI 요소의 위치를 로컬 좌표로 설정
            obj.GetComponent<RectTransform>().anchoredPosition = localPoint;

            ExplanationObject = obj;

        }

    }

    public void SetExplanation(GameObject obj)
    {
        Explanation = obj;
    }

    public void SetCanvas(GameObject cnavas)
    {
        Canvas = cnavas;
    }

    public void SetUseDescriptions(bool usedescriptions)
    {
        UseDescriptions = usedescriptions;
    }
}
