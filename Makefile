.PHONY: clean All

All:
	@echo "----------Building project:[ UOCJocs - Menu ]----------"
	@"$(MAKE)" -f  "UOCJocs.mk"
clean:
	@echo "----------Cleaning project:[ UOCJocs - Menu ]----------"
	@"$(MAKE)" -f  "UOCJocs.mk" clean
