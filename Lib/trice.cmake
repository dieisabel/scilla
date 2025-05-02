set(TRICE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/trice)

target_include_directories(${PROJECT_NAME} PUBLIC ${TRICE_DIR}/src)
target_sources(${PROJECT_NAME} PRIVATE
    ${TRICE_DIR}/src/cobsDecode.c
    ${TRICE_DIR}/src/cobsEncode.c
    ${TRICE_DIR}/src/tcobsv1Decode.c
    ${TRICE_DIR}/src/tcobsv1Encode.c
    ${TRICE_DIR}/src/trice.c
    ${TRICE_DIR}/src/trice8.c
    ${TRICE_DIR}/src/trice16.c
    ${TRICE_DIR}/src/trice32.c
    ${TRICE_DIR}/src/trice64.c
    ${TRICE_DIR}/src/triceAuxiliary.c
    ${TRICE_DIR}/src/triceDoubleBuffer.c
    ${TRICE_DIR}/src/triceRingBuffer.c
    ${TRICE_DIR}/src/triceStackBuffer.c
    ${TRICE_DIR}/src/triceStaticBuffer.c
    ${TRICE_DIR}/src/triceUart.c
    ${TRICE_DIR}/src/xtea.c
)
