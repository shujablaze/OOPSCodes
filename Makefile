.PHONY: clean All

All:
	@echo "----------Building project:[ oopsLab - Debug ]----------"
	@cd "oopsLab" && "$(MAKE)" -f  "oopsLab.mk"
clean:
	@echo "----------Cleaning project:[ oopsLab - Debug ]----------"
	@cd "oopsLab" && "$(MAKE)" -f  "oopsLab.mk" clean
