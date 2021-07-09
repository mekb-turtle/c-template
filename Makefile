BUILD         := build
SRC           := $(shell find ./ -type f -name '*.c')
OUT           := $(BUILD)/build
BUILD_FLAGS   := -O2
LIBARY_FLAGS  := 
.PHONY: all
all:
	@make clean -sB
	@make build -sB
clean:
	@echo cleaning...
	rm -rfv $(BUILD)
build:
	@echo building...
	mkdir -v $(BUILD)
	gcc $(SRC) -o $(OUT) $(BUILD_FLAGS) $(LIBARY_FLAGS) 
	@echo compiled. run with make run
run:
	@$(OUT)

