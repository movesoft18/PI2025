from ultralytics import YOLO
import cv2

# Загрузить модель
model = YOLO("yolo26n.pt")  # загрузить официальную модель
#model = YOLO("path/to/best.pt")  # загрузить пользовательскую модель

# Получи предсказания с помощью модели
results = model("street1.jpg", conf=0.5)  # получи предсказание для изображения
image = cv2.imread("street1.jpg")
cv2.imshow("Original", image)
# Обратись к результатам
for result in results:
    #xywh = result.boxes.xywh  # центр-x, центр-y, ширина, высота
    #xywhn = result.boxes.xywhn  # normalized
    xyxy = result.boxes.xyxy  # левый верхний угол-x, левый верхний угол-y, правый нижний угол-x, правый нижний угол-y
    #xyxyn = result.boxes.xyxyn  # normalized
    names = [result.names[cls.item()] for cls in result.boxes.cls.int()]  # название класса каждой рамки
    confs = result.boxes.conf  # оценка уверенности каждой рамки
    count = len(result.boxes)
    if count > 0:
        for i in range(0,count):
            x1 = int(xyxy[i][0])
            y1 = int(xyxy[i][1])
            x2 = int(xyxy[i][2])
            y2 = int(xyxy[i][3])
            conf = confs[i]
            name = names[i]
            class_obj = int(result.boxes.cls[i])
            text = f'Объект {i+1}: {name} conf={conf:.2f} x1 {x1} y1 {y1} x2 {x2} y2 {y2}'
            print (text)
    cv2.imshow("Street objects", result.plot())
    cv2.waitKey()
    cv2.destroyAllWindows()