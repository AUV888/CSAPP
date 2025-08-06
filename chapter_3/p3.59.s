# C prototype
# void store_prod(int128_t *dest, int64_t x, int64_t y){
#     *dest = x * (int128_t) y;
# }
# arguments are in rdi rsi rdx

store_prod:
                        # let x = Xh * 2^64 + Xl, y = Yh * 2^64 + Yl
                        # thus p = (Xh*Yl + Xl*Yh) * (2^64) + Xl*Yl
    movq  %rdx, %rax    # copy y
    cqto                # extend y to oct word
    movq  %rsi, %rcx    # copy x
    sarq  $63,  %rcx    # store Xh in rcx
    imulq %rax, %rcx    # calc Yl * Xh and store in rcx
    imulq %rsi, %rdx    # calc Xl * Yh and store in rdx
    addq  %rdx, %rcx    # calc higher 64 bit of 128 bit product and store in rcx
    mulq  %rsi          # calc Xl * Yl and store in rax
    addq  %rcx, %rdx    # calc Xl*Yl mod 2^64 (already stored in rdx) + rcx
    movq  %rax, (%rdi)  # move lower 64 bit to destination
    movq  %rdx, 8(%rdi) # move higher 64 bit to destination + 8
    ret