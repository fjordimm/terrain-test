@cd .\TerrainTestProject\build\
@echo ======================================================================================
@echo ===== REMINDER: Dr. Memory can make the program much slower, so give it a second =====
@echo ======================================================================================
@drmemory -leaks_only -brief -results_to_stderr -batch -- .\libs\Fjordimm3DEngine\Fjordimm3DEngineExec.exe
@cd ..\..