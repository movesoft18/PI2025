from ultralytics import YOLO

# Load a model
model = YOLO("yolo26x-cls.pt")  # load an official model
#model = YOLO("path/to/best.pt")  # load a custom model

# Predict with the model
results = model("lion_dog.jpg", verbose=False)  # predict on an image

# Access the results
for result in results:
    top1 = result.probs.top1  # top predicted class ID
    top1_conf = result.probs.top1conf  # top prediction confidence
    top1_name = result.names[top1]  # top predicted class name
    print(f'Предсказано: {top1_name} - уверенность {top1_conf*100}%')
    i = 0
    print('ТОП 5:')
    for item in result.probs.top5:
        top = item
        name = result.names[top]
        print(f'Объект {name}, уверенность {result.probs.top5conf[i]}')
        i += 1
        