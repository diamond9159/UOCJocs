.PHONY: clean All

All:
	@echo "----------Building project:[ UOCJocs - Test ]----------"
	@"$(MAKE)" -f  "UOCJocs.mk"
clean:
	@echo "----------Cleaning project:[ UOCJocs - Test ]----------"
	@"$(MAKE)" -f  "UOCJocs.mk" clean
