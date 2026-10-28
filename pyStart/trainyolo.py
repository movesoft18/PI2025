from ultralytics import YOLO

# Загружаем предобученную модель (начинаем не с нуля)
model = YOLO("yolov8n.pt")

# Запускаем обучение
model.train(
    data="datasets/balloons/data.yaml",
    epochs=50,
    imgsz=640,
    batch=16,
    name="my_first_model",
)