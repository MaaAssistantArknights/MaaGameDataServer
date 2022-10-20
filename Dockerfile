FROM azul/zulu-openjdk-alpine:17-latest
WORKDIR /app

ENV RUN_PROFILE prod

ENV DB_URL ""
ENV DB_USER ""
ENV DB_PASS ""

RUN apk --no-cache add bash

COPY .mvn/ .mvn
COPY mvnw pom.xml ./
RUN ./mvnw dependency:resolve
COPY src ./src
RUN ./mvnw package -Dmaven.test.skip=true

ENTRYPOINT ["bash", "--"]

EXPOSE 8080

CMD [ \
    "/usr/local/jre/bin/java", \
    "-jar", \
    "/app/target/MaaGameDataServer.jar", \
    "--spring.profiles.active=$RUN_PROFILE", \
    "--spring.datasource.url=$DB_URL", \
    "--spring.datasource.username=$DB_USER", \
    "--spring.datasource.password=$DB_PASS" \
    ]
