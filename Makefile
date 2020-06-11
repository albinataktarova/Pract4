.PHONY: clean All

All:
	@echo "----------Building project:[ Pr1 - Debug ]----------"
	@cd "Pr1" && "$(MAKE)" -f  "Pr1.mk"
clean:
	@echo "----------Cleaning project:[ Pr1 - Debug ]----------"
	@cd "Pr1" && "$(MAKE)" -f  "Pr1.mk" clean
