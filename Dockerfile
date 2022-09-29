FROM azul/zulu-openjdk-alpine:17-latest
WORKDIR /app

ENV RUN_PROFILE prod

RUN apk --no-cache add bash

COPY .mvn/ .mvn
COPY mvnw pom.xml ./
RUN ./mvnw dependency:resolve
COPY src ./src
RUN ./mvnw package -Dmaven.test.skip=true

ENTRYPOINT ["bash", "--"]

EXPOSE 8080

CMD ["java", "-jar", "/app/target/MaaGameDataServer.jar", "--spring.profiles.active=$RUN_PROFILE"]
