FROM azul/zulu-openjdk-alpine:17-latest
WORKDIR /app

ENV PROFILE prod

RUN apk --no-cache add bash

COPY target ./

ENTRYPOINT ["bash", "--"]

EXPOSE 8080

CMD ["java", "-jar", "/app/MaaGameDataServer.jar", "--spring.profiles.active=$PROFILE"]
